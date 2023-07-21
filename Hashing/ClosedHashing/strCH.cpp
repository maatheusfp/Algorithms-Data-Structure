#include <iostream>
#include <string.h>
using namespace std;

typedef struct entry{
    char name[50];
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
    return d;
}

int h(Dict* d, char name[]){
    int s = strlen(name);
    int sum = 0; 

    for (int i = 0; i < s; i++){
        sum += name[i];
    }
    return abs(sum) % d->m;
}

int find(Dict* d, char nome[]){
    int pos = h(d, nome);

    int value = strcmp(d->H[pos].name, nome);
    if (value == 0){
        return pos;
    }

    for (int i = 0; i < d->m; i++){
        int value = strcmp(d->H[i].name, nome);
        if (value == 0){
            return i;
        }
    }
    return -1;    
}

void insert(Dict* d, char nome[]){
    if (d->cnt >= d->m || find(d, nome) != -1){
        return;
    }
    int pos = h(d, nome);

    if (strlen(d->H[pos].name) != 0){
        do {
             pos = (pos + 1) % d->m;
        } while (strlen(d->H[pos].name) != 0);
    }   

    Entry entry;
    int s = strlen(nome);

    for (int i = 0; i < s; i++){
        entry.name[i] = nome[i];
    }
    for (int j = s; j < 50; j++){
        entry.name[j] = '\0';
    }

    d->H[pos] = entry;
    d->cnt++;
}

int remove(Dict* d, char nome[]){
    int s = strlen(nome);
    int pos = find(d, nome);

    if (pos != -1){
        for (int i = 0; i < s; i++){
            d->H[pos].name[i] = '\0';
        }
        
        return 1;
    }

    return -1;
}

int main(){
    int size; 
    char nome[50];
    string comando;
    cin >> size;

    Dict* d = create_dict(size);

    while (comando != "fim"){
        cin >> comando >> nome;

        if (comando == "add"){
            insert(d, nome);
        }
        if (comando == "sch"){
            int value = find(d, nome);
            cout << nome << " " << value << endl;
        }   
        if (comando == "rmv"){
            int value = remove(d, nome);
        }
    }

    return 0;
}