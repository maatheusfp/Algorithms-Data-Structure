#include <iostream>
#include <string.h>

using namespace std;

int h(char CPF, int n){
    int soma = 0;

    for (int i = 0; i < 12; i++){
        int somador = atoi(CPF[i]);
        soma += somador;
    }
    return soma%n;
}

typedef struct entry{
    char CPF[12];
    string nome;
} Entry;

typedef struct hashDict {
    int m, cnt; 
    Entry* H;
    int Perm[9] = {2, 5, 7, 8, 9, 1, 3, 4, 6};
} HashDict;

int find(HashDict* d, char CPF[12]){
    int pos = h(CPF);
    int newPos = pos;
    int i = 0;
    int contador = 0;

    do {
        if (d->H[newPos].CPF == CPF){
            return newPos;
        }
        i++;
        int offset = d->Perm[i - 1];
        newPos = (pos + offset)%d->m;
        contador++;
    } while (contador <= 10);

    return -1;
}

void insert(HashDict* d, char CPF[12], string nome){
    if(d->cnt >= d->m || find(d, CPF) != -1){
        return;
    }

    int pos = h(CPF);
    int newPos;
    if (d->H[pos].CPF != 0){
        int i = 0;
        do {
            i++;
            int offset = d->Perm[i - 1];
            newPos = (pos + offset)%d->m;
        } while (d->H[newPos].CPF != 0);
        pos = newPos;
    }
    Entry entry;
    entry.CPF = CPF;
    entry.nome = nome;
    d->H[pos] = entry;
    d->cnt++;
}

HashDict* create_dict(int size){
    HashDict* d = (HashDict*) malloc(sizeof(HashDict));
    d->m = size;
    d->cnt = 0;
    d->H = new Entry[size];
    return d;
}

int main(){


    return 0;
}