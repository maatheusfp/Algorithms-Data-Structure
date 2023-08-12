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

long long int ranking(BSTnode* rt){
    if (rt == nullptr) return 0;
    return 1 + rt->size_left + rt->size_right;
}

long long int findIndex(BSTnode* rt, long long int key){
    if (rt == nullptr) return -9000000;
    if ((rt->key) > key) {
        return findIndex(rt->left, key);
    } else if (rt->key == key) {
        return 1 + rt->size_left;
    } else {
        return 1 + rt->size_left + findIndex(rt->right, key);
    }
}

BSTnode* rightRotate(BSTnode* rt){  
    BSTnode* l = rt->left;
    BSTnode* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    rt->size_left = ranking(rt->left);
    rt->size_right = ranking(rt->right);
    l->size_right = ranking(l->right);
    l->size_left = ranking(l->left);
    return l;
}

BSTnode* leftRotate(BSTnode* rt){  
    BSTnode* r = rt->right;
    BSTnode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    
    rt->size_left = ranking(rt->left);
    rt->size_right = ranking(rt->right);
    r->size_right = ranking(r->right);
    r->size_left = ranking(r->left);
    return r;
}

BSTnode* insertHelp(BSTnode* rt, long long int key){
    if (rt == nullptr){
        return create_bstnode(key);
    }
    if (rt->key > key){
        rt->left = insertHelp(rt->left, key);
        rt->size_left++;
    }
    else {
        rt->right = insertHelp(rt->right, key);
        rt->size_right++;
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

void insert(BST* bst, long long int key){
    bst->root = insertHelp(bst->root, key);
    bst->nodecount++;
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
            int index = findIndex(bst->root, x);
            if (index < 0){
                cout << "Data tidak ada" << endl;
            }
            else {
                cout << index << endl;
            }
        }
    }
    return 0;
}