#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct bstnode {
    int key;
    int element;
    int height;
    int rank;
    bstnode* left;
    bstnode* right;
} BSTnode;

typedef struct bst {
    BSTnode* root;
    int nodecount;
} BST;

BSTnode* create_bstnode(int key, int element){
    BSTnode* n = (BSTnode*) malloc(sizeof(BSTnode)); 
    n->key = key;
    n->element = element;
    n->height = 0;
    n->rank = 1;
    n->left = n->right = nullptr;
    return n;
}

BST* create_bst(){
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = nullptr;
    bst->nodecount = 0;
    return bst;
}

int h(BSTnode* rt){
    if (rt == nullptr){
        return -1;
    }
    return rt->height;
}

int getBalance(BSTnode* rt){
    if (rt == nullptr){
        return 0;
    }
    return (h(rt->left) - h(rt->right));
}

BSTnode* rightRotate(BSTnode* rt){  
    BSTnode* l = rt->left;
    BSTnode* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

BSTnode* leftRotate(BSTnode* rt){  // o nó principal da atual rotação receberá o valor do ranking do nó da direita.
    BSTnode* r = rt->right;
    BSTnode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

BSTnode* insertHelp(BSTnode* rt, int key, int element){
    if (rt == nullptr){
        return create_bstnode(key, element);
    }
    if (rt->key > key){
        rt->left = insertHelp(rt->left, key, element);
    }
    else {
        rt->right = insertHelp(rt->right, key, element);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if (balance < -1 && key >= rt->right->key){
        return leftRotate(rt);
    }
    if (balance > 1 && key < rt->left->key){
        return rightRotate(rt);
    }
    if (balance > 1 && key >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && key < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
}

void insert(BST* bst, int key, int e){
    bst->root = insertHelp(bst->root, key, e);
    bst->nodecount++;
}