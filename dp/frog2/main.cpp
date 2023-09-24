#include <bits/stdc++.h>
using namespace std;

int dp(int n, int k, int custo[], int alturas[]){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j <= i + k; j++){
            if (j < n){
                custo[j] = min(custo[j], custo[i] + abs(alturas[j] - alturas[i]));
            }
        }
    }
    return custo[n - 1];
}

int main(){
    int n, k, altura;
    cin >> n >> k;
    int alturas[n];
    int custo[n];
    custo[0] = 0;

    for (int i = 0; i < n; i++){
        cin >> altura;
        alturas[i] = altura;
    }

    for (int i = 1; i < n; i++){
        custo[i] = INT_MAX;
    }

    cout << dp(n, k, custo, alturas);

    return 0;
}