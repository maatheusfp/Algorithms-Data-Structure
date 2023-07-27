#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct bstNode {
    int key;
    int element;
    bstNode* left;
    bstNode* right;
} BstNode;

typedef struct bst {
    BstNode* root;
    int nodeCount;
} BST;

BstNode* create_bstNode(int key, int e){
    BstNode* n = (BstNode*) malloc(sizeof(BstNode));
    n->key = key;
    n->element = e;
    n->left = n->right = NULL;
    return n; 
}

BST* create_bst(){
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    bst->nodeCount = 0;
    return bst;
}

int findhelp(BstNode* rt, int key){
    if (rt == NULL){
        return -1;
    }
    if (rt->key > key){
        return findhelp(rt->left, key);
    }
    else if (rt->key = key){
        return rt->element;
    }
    else {
        return findhelp(rt->right, key);
    }
}

int find(BST* bst, int key){
    return findhelp(bst->root, key);
}

BstNode* inserthelp(BstNode* rt, int key, int e){
    if (rt == NULL){
        return create_bstNode(key, e);
    }
    if (rt->key > key) {
        rt->left = inserthelp(rt->left, key, e);
    }
    else {
        rt->right = inserthelp(rt->right, key, e);
    }
    return rt;
}

void insert(BST* bst, int key, int e){
    bst->root = inserthelp(bst->root, key, e);
    bst->nodeCount++;
}

int main(){

    return 0;
}