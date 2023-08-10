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
        d->H[i].name = "";
    }
    return d;
}

int h(Dict* d, string name){
    int sum = 0;
    int size = name.length();

    for (int i = 0; i < size; i++){
        sum += name[i]*(i + 1);
    }

    return (19*(sum)) % 101;
}

int find(Dict* d, string name){
    int pos = h(d, name);

    if (name == d->H[pos].name){
        return pos;
    }

    for (int i = 0; i <= 20; i++){
        if (name == (d->H[pos + (i*i) + (23*i)].name)){
            return pos;
        }
    }
    return -1;    
}

void insert(Dict* d, string nome){
    if (d->cnt >= d->m || find(d, nome) != -1){
        return;
    }
    int pos = h(d, nome);
    
    if (d->H[pos].name == ""){
		d->H[pos].name = nome;
		d->cnt++;
	}
    else {
        int newPos;
        int found = 0;
        int j = 1;
        while(found == 0 && j <= 20){
		    newPos = (pos+(j*j)+(23*j))%101;
            if (d->H[newPos].name == ""){
                d->H[newPos].name = nome;
                found = 1;
                d->cnt++;
	            }
            j++;    
		}
	}
}
	

void remove(Dict* d, string nome){
    for (int i = 0; i < 101; i++){
        if(d->H[i].name == nome){
            d->H[i].name = "";
            d->cnt--;
            if (d->cnt < 0){
                d->cnt = 0;
            }
        }
    }
}

int main(){
    int n, c;
    string comando, key;
    cin >> n;

    while (n--){
        Dict* dict = create_dict(101);

        cin >> c;
        for (int i = 0; i < c; i++){
            cin >> comando;

            if (comando.substr(0,3) == "ADD"){
                key = comando.substr(4);
                insert(dict, key);
            }

            else {
                key = comando.substr(4);
                remove(dict, key);
            }
        }

        cout << dict->cnt << endl;

        for (int j = 0; j < 101; j++){
            if (dict->H[j].name != ""){
                cout << j << ":" << dict->H[j].name << endl;
            }
        }
    }

    return 0;
}