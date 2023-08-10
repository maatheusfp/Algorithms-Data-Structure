#include <iostream>
#include <string.h>
using namespace std;

typedef struct entry{
    string name;
} Entry;

typedef struct dict {
    int m, cnt;
    Entry* H;
} Dict;

Dict* create_dict(int size){
    Dict* d = (Dict*) malloc(sizeof(Dict));
    d->m = size;
    d->cnt = 0;
    d->H = new Entry[size];
    for (int i = 0; i < size; i++){
        d->H[i].name = '\0';
    }
    return d;
}

int main(){
    Dict* dict = create_dict(10);

    for (int i = 0; i < 10; i++){
        cout << dict->H[i].name << endl;
    }
    return 0;
}