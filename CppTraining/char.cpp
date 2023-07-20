#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
    int soma;
    char word[12];
    cin >> word;

    for (int i = 0; i < 11; i++){
        int somador = word[i] - '0';
        soma += somador;
    }
    cout << soma << endl;
    return 0;
}