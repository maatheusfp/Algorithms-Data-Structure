#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct bstnode {
    int key;
    int element;
    int height;
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
    return rt->height; /* como calcula a altura da árvore? */
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
    int n, numero;
    string comando;
    cin >> n;

    BST* bst = create_bst();

    for (int i = 0; i < n; i++){
        cin >> comando; 
        if (comando == "insert"){
            cin >> numero;
            insert(bst, numero, numero);
        }
        else if(comando == "pre"){
            preOrder(bst->root);
            cout << endl;
        }
        else if(comando == "in"){
            inOrder(bst->root);
            cout << endl;
        }
        else {
            posOrder(bst->root);
            cout << endl;
        }
    }

    return 0;
}