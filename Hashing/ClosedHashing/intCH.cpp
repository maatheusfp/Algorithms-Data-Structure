#include <iostream>
#include <string.h>

using namespace std;

typedef struct entry{
    char CPF[12];
    string nome;
} Entry;

typedef struct hashDict {
    int m, cnt; 
    Entry* H;
} HashDict;

int h(HashDict* d, char CPF[]){
    int soma = 0;
    int somador;

    for (int i = 0; i < 11; i++){
        somador = CPF[i] - '0';
        soma += somador;
    }
    return soma % d->m;
}

int find(HashDict* d, char CPF[12], int perm[]){
    int pos = h(d, CPF);
    int newPos = pos;
    int i = 0;
    int contador = 0;

    do {
        if ((strcmp(d->H[newPos].CPF, CPF)) == 1){
            return newPos;
        }
        i++;
        int offset = perm[i - 1];
        newPos = (pos + offset)%d->m;
        contador++;
    } while (contador <= d->m);

    return -1;
}

void insert(HashDict* d, char CPF[12], string nome, int perm[]){
    if(d->cnt >= d->m || find(d, CPF, perm) != -1){
        return;
    }

    int pos = h(d, CPF);
    int newPos;
    if ((strcmp(d->H[pos].CPF, NULL)) != 0){
        int i = 0;
        do {
            i++;
            int offset = perm[i - 1];
            newPos = (pos + offset)%d->m;
        } while ((strcmp(d->H[newPos].CPF, NULL)) != 0);
        pos = newPos;
    }
    Entry entry;
    for (int j = 0; j < 11; j++){
        entry.CPF[j] = CPF[j]; 
    }
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
    int n, c;
    cin >> n;
    int perm[n - 1];
    char CPF[12];
    string comando;
    string nome;

    HashDict* d = create_dict(n);

    for (int i = 0; i < n - 1; i++){
        cin >> perm[i];
    }
    cin >> c;

    for (int j = 0; j < c; j++){
        cin >> comando >> CPF;

        if (comando == "add"){
            cin >> nome;
            insert(d, CPF, nome, perm);
            cout << "inserido" << endl;
        }
        else {
            if (find(d, CPF, perm) != -1){
                cout << "adicionado" << endl;
            }
            else {
                cout << "nao" << endl;
            }
        }
    }
    return 0;
}