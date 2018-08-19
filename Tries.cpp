//
//  main.cpp
//  Tries
//
//  Created by Shivsankar Ramasubramanian on 12/26/15.
//  Copyright © 2015 Shivsankar Ramasubramanian. All rights reserved.
//

#include <iostream>

#define ALPHABET_SIZE (26)
#define CHAR_INDEX(c) (int(c)-int('a'))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct trieNode
{
    int value;
    trieNode *children[ALPHABET_SIZE];
};

struct trie
{
    trieNode *root;
    int count;
};

trieNode* getNode()
{
    trieNode *pNode = NULL;
    pNode = (trieNode*)malloc(sizeof(trieNode));
    
    if (pNode)
    {
        pNode->value=0;
        
        for (int i=0; i<ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

void initialize(trie *pTrie)
{
    pTrie->root = getNode();
    pTrie->count=0;
}

void insert(trie *pTrie, char key[])
{
    int index;
    int length = strlen(key);
    trieNode *pCrawl;
    
    pTrie->count++;
    pCrawl = pTrie->root;
    
    for (int level=0; level<length; level++)
    {
        index = CHAR_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    
    pCrawl->value=pTrie->count;
}

int search(trie *pTrie, char key[])
{
    int index;
    int length = strlen(key);
    trieNode *pCrawl;
    
    pCrawl = pTrie->root;
    
    for (int level=0; level<length; level++)
    {
        index = CHAR_INDEX(key[level]);
        if (!pCrawl->children[index])
            return 0;
        pCrawl = pCrawl->children[index];
    }
    
    return (0!=pCrawl && pCrawl->value);
}



int main(int argc, const char * argv[])
{
    using namespace std;
    
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie trie;
    
    char output[][32] = {"Not present in trie", "Present in trie"};
    
    initialize(&trie);
    
    /*cout<<keys[0]<<"\n";
    cout<<sizeof(keys)<<"\n";
    cout<<sizeof(keys[0])<<"\n";
    cout<<ARRAY_SIZE(keys)<<"\n";*/
    
    for (int i=0; i<ARRAY_SIZE(keys); i++)
        insert(&trie, keys[i]);
    
    cout<<trie.root->children[0]<<"\n";
    cout<<trie.root->value<<"\n";
    
    cout<<"the: "<<output[search(&trie, "the")]<<"\n";
    cout<<"these: "<<output[search(&trie, "these")]<<"\n";
    
    return 0;
}




