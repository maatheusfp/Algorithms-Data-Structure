#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct bstnode {
    int key;
    int element;
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
    n->left = n->right = nullptr;
    return n;
}

BST* create_bst(){
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = nullptr;
    bst->nodecount = 0;
    return bst;
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

int main(){
    int n, p;
    cin >> n;

    BST* bst = create_bst();

    for (int i = 0; i < n; i++){
        cin >> p;
        insert(bst, p, p);
    }

    cout << "Pre" << " " << "order" << " " << ":" << " "; 
    preOrder(bst->root);
    cout << endl;

    cout << "In" << " " << "order" << " " << " " << ":" << " "; 
    inOrder(bst->root);
    cout << endl;

    cout << "Post" << " " << "order" << ":" << " "; 
    posOrder(bst->root);
    cout << endl;

    return 0;
}