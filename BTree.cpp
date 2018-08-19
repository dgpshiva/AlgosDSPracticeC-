//
//  main.cpp
//  BTree
//
//  Created by Shivsankar Ramasubramanian on 12/25/15.
//  Copyright © 2015 Shivsankar Ramasubramanian. All rights reserved.
//

#include <iostream>

template <class Object>
struct node
{
    Object keyValue;
    node *left;
    node *right;
};

template <class Object>
class BTree
{
public:
    BTree();
    ~BTree();

    void insert(Object value);
    node<Object> *search(Object value);

    void destroyTree();

private:
    void insert(node<Object> *leaf, Object value);
    node<Object> *search(node<Object> *leaf, Object value);
    void destroyTree(node<Object> *leaf);

    node<Object> *root;
};

template <class Object>
BTree<Object>::BTree()
{
    root=NULL;
}

template <class Object>
BTree<Object>::~BTree()
{
    destroyTree();
}

template <class Object>
void BTree<Object>::destroyTree(node<Object> *leaf)
{
    if (leaf!=NULL)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

template <class Object>
void BTree<Object>::insert(node<Object> *leaf, Object value)
{
    if (value < leaf->keyValue)
    {
        if (leaf->left != NULL)
            insert(leaf->left, value);
        else
        {
            leaf->left = new node<Object>;
            leaf->left->keyValue = value;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (value >= leaf->keyValue)
    {
        if (leaf->right != NULL)
            insert(leaf->right, value);
        else
        {
            leaf->right = new node<Object>;
            leaf->right->keyValue = value;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}


template <class Object>
node<Object> *BTree<Object>::search(node<Object> *leaf, Object value)
{
    if (leaf!=NULL)
    {
        if (leaf->keyValue == value)
            return leaf;
        else if (value<leaf->keyValue)
            return search(leaf->left, value);
        else
            return search(leaf->right, value);
    }
    else return NULL;
}


template <class Object>
void BTree<Object>::insert(Object value)
{
    if (root!=NULL)
        insert(root, value);
    else
    {
        root = new node<Object>;
        root->keyValue = value;
        root->left = NULL;
        root->right = NULL;
    }
}

template <class Object>
node<Object> *BTree<Object>::search(Object value)
{
    return search(root, value);
}

template <class Object>
void BTree<Object>::destroyTree()
{
    destroyTree(root);
}



int main(int argc, const char * argv[])
{
    using namespace std;

    int c;
    BTree<int> b;
    int svalue;
    node<int> *n;

    cout<<"Enter the no. of values to enter:";
    cin>>c;
    cout<<"\n";

    for (int i=0; i<c; i++)
    {
        int value=0;
        cout<<"Enter the value: ";
        cin>>value;
        cout<<"\n";
        b.insert(value);
    }

    cout<<"Enter the vaue to search: ";
    cin>>svalue;
    cout<<"\n";
    n = b.search(svalue);
    cout<<"In tree: "<<n->keyValue<<"\n";

    return 0;
}
