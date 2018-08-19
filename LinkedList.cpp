//
//  main.cpp
//  LinkedList
//
//  Created by Shivsankar Ramasubramanian on 12/22/15.
//  Copyright © 2015 Shivsankar Ramasubramanian. All rights reserved.
//

#include <iostream>

template <class Object>
struct node
{
    Object element;
    node *next;
};

int main(int argc, const char * argv[])
{
    using namespace std;
    
    int c=0;
    int fvalue=0;
    int lvalue=0;
    
    cout<<"Enter the first node value: ";
    cin>>fvalue;
    cout<<"\n";
    
    node<int> *n;
    node<int> *h;
    node<int> *t;
    n = new node<int>;
    n->element = fvalue;
    h=n;
    t=n;
    
    cout<<"Enter the more number of nodes to create: ";
    cin>>c;
    cout<<"\n";
    
    for (int i=0; i<c; i++)
    {
        int value=0;
        
        cout<<"Enter the value: ";
        cin>>value;
        cout<<"\n";
        n = new node<int>;
        n->element = value;
        t->next = n;
        t = n;
    }
    
    cout<<"Enter the last node value: ";
    cin>>lvalue;
    n = new node<int>;
    n->element = lvalue;
    n->next = NULL;
    t->next = n;
    t = n;
    
    node<int> *p;
    p = h;
    
    while (p->next!=NULL)
    {
        cout<<p->element;
        cout<<"\n";
        p=p->next;
    }
    cout<<p->element;
    cout<<"\n";
    return 0;
    
}