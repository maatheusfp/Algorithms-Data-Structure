#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int s, int v[], int w[], vector<vector<int>> F){
    for (int i = 1; i <= n; i++){
        for (int rw = 0; rw <= s; rw++){
            F[i][rw] = F[i - 1][rw];

            if (w[i] <= rw){
                F[i][rw] = max(F[i][rw], F[i - 1][rw - w[i]] + v[i]);
            }
        }
    }
    
    return F[n][s];
}

int main(){
    int s, n, peso, valor;
    cin >> s >> n;

    vector<vector<int>> F(n + 1, vector<int>(s + 1, 0));

    int v[n + 1];
    int w[n + 1];

    v[0] = -1;
    w[0] = -1;

    for(int i = 1; i <= n; i++){
        cin >> peso >> valor;
        w[i] = peso;
        v[i] = valor;
    }

    cout << knapsack(n, s, v, w, F) << endl;

    return 0;
}