#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct bstnode {
    int key;
    int height;
    string modelo, cor;
    bstnode* left;
    bstnode* right;
} BSTnode;

typedef struct bst {
    BSTnode* root;
    int nodecount;
} BST;

BSTnode* create_bstnode(int key, string modelo, string cor){
    BSTnode* n = (BSTnode*) malloc(sizeof(BSTnode)); 
    n->key = key;
    n->modelo = modelo;
    n->cor = cor;
    n->height = 0;
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

BSTnode* leftRotate(BSTnode* rt){
    BSTnode* r = rt->right;
    BSTnode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

BSTnode* insertHelp(BSTnode* rt, int key, string modelo, string cor){
    if (rt == nullptr){
        return create_bstnode(key, modelo, cor);
    }
    if (rt->key > key){
        rt->left = insertHelp(rt->left, key, modelo, cor);
    }
    else {
        rt->right = insertHelp(rt->right, key, modelo, cor);
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

void preOrder(BSTnode* rt){
    if (rt != nullptr){
        cout << rt->key << " ";
        preOrder(rt->left);
        preOrder(rt->right);
    }
}

void inOrder(BSTnode* rt){
    if (rt != nullptr){
        inOrder(rt->left);
        cout << rt->key << " ";
        inOrder(rt->right);
    }
}

void posOrder(BSTnode* rt){
    if (rt != nullptr){
        posOrder(rt->left);
        posOrder(rt->right);
        cout << rt->key << " ";
    }
}
