#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct bstnode {
    long long int key, height, size_left, size_right;
    bstnode* left;
    bstnode* right;
} BSTnode;

typedef struct bst {
    BSTnode* root;
    int nodecount;
} BST;

BSTnode* create_bstnode(long long int key){
    BSTnode* n = (BSTnode*) malloc(sizeof(BSTnode)); 
    n->key = key;
    n->height = 0;
    n->size_left = 0;
    n->size_right = 0;
    n->left = n->right = nullptr;
    return n;
}

BST* create_bst(){
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = nullptr;
    bst->nodecount = 0;
    return bst;
}

long long int h(BSTnode* rt){
    if (rt == nullptr){
        return -1;
    }
    return rt->height;
}

long long int getBalance(BSTnode* rt){
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
    rt->size_left = l->size_right;
    l->size_right = (rt->size_right + rt->size_left)+1;
    return l;
}

BSTnode* leftRotate(BSTnode* rt){  
    BSTnode* r = rt->right;
    BSTnode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    rt->size_right = r->size_left;
    r->size_left = (rt->size_left + rt->size_right) + 1;
    return r;
}

BSTnode* insertHelp(BSTnode* rt, long long int key){
    if (rt == nullptr){
        return create_bstnode(key);
    }
    if (rt->key > key){
        rt->left = insertHelp(rt->left, key);
    }
    else {
        rt->right = insertHelp(rt->right, key);
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if (rt->right != nullptr) rt->size_right = (rt->right->size_right) + (rt->right->size_left);
    if (rt->left != nullptr) rt->size_left = (rt->left->size_right) + (rt->left->size_left);

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

void insert(BST* bst, long long int key){
    bst->root = insertHelp(bst->root, key);
    bst->nodecount++;
}

long long int findIndex(BSTnode* rt, long long int key){
    if (rt->key == key){
        return rt->size_left + 1;
    }
    else if (rt->key < key){
        return (rt->size_left) + 1 + findIndex(rt->right, key);
    }
    else {
        findIndex(rt->left, key);
    }
}

bool present(BSTnode* rt, long long int key){
    if (rt == nullptr) return false;

    if (rt->key == key){
        return true;
    }
    else if (rt->key < key){
        return (rt->right, key);
    }
    else {
        return present(rt->left, key);
    }
}

int main(){
    int q, y, x;
    cin >> q;
    
    BST* bst = create_bst();

    while(q--){
        cin >> y >> x;

        if (y == 1){
            insert(bst, x);
        }
        else {
            if (present(bst->root, x) == false) cout << "Data tidak ada" << endl;
            else {
                int index = findIndex(bst->root, x);
                cout << index << endl;
            }
        }
    }

    return 0;
}