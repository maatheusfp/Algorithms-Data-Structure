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

HashDict* create_dict(int size){
    HashDict* d = (HashDict*) malloc(sizeof(HashDict));
    d->m = size;
    d->cnt = 0;
    d->H = new Entry[size];
    return d;
}

int find(HashDict* d, char CPF[], int perm[]){
    int pos = h(d, CPF);
    int newPos = pos;
    int i = 0;
    
    do {
        int value = strcmp(d->H[newPos].CPF, CPF);
        if ((value == 0)){
            return newPos;
        }
        i++;
        int offset = perm[i - 1];
        newPos = (pos + offset)%d->m;
    } while (i <= d->m - 2); 

    return -1;
}

int remove(hashDict* d, char CPF[], int perm[]){
    int value = find(d, CPF, perm);

    if (value == -1){
        return -1;
    }

    for (int j = 0; j < 11; j++){
        d->H[value].CPF[j] = '\0';
    }
    d->H[value].nome = '\0';
    return 1;
}

void insert(HashDict* d, char CPF[], string nome, int perm[]){
    if(d->cnt >= d->m || find(d, CPF, perm) != -1){
        return;
    }    
    int pos = h(d, CPF);
    int newPos;
    if (strlen(d->H[pos].CPF) != 0){
        int i = 0;
        do {
            i++;
            int offset = perm[i - 1];
            newPos = (pos + offset)%d->m;
        } while ((strlen(d->H[pos].CPF) != 0) && i <= d->m -2);
        pos = newPos;
    }
    Entry entry;
    for (int j = 0; j < 11; j++){
        entry.CPF[j] = CPF[j];
    }
    entry.CPF[11] = '\0';
    entry.nome = nome;
    d->H[pos] = entry;
    d->cnt++;
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
        else if (comando == "find"){
            if (find(d, CPF, perm) != -1){
                cout << "adicionado" << endl;
            }
            else {
                cout << "nao" << endl;
            }            
        }
        else {
            if (remove(d, CPF, perm) == 1){
                cout << "removido" << endl;
            }
            else {
                cout << "nao2" << endl;
            }
        }
    }
    return 0;
}