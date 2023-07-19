#include <iostream>
using namespace std;

int h(int k){
    int result = k%10;
    return result;
}

typedef struct entry{
    int* k;
    int v;
} Entry;

typedef struct hashDict {
    int m, cnt; 
    Entry* H;
    int* Perm;
} HashDict;

int* create_permutation(){

}

HashDict* create_dict(int size){
    HashDict* d = (HashDict*) malloc(sizeof(HashDict));
    d->m = size;
    d->cnt = 0;
    d-> h = new Entry[size];
    d->Perm = create_permutation()
    return d;
}

int main(){
    return 0;
}