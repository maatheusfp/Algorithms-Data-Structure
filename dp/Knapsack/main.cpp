#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll knapsack(ll i, ll j, ll w[], ll v[], vector<vector<ll>> F){
    ll value;
    if (F[i][j] < 0) {
        if (j < w[i]) value = knapsack(i - 1, j, w, v, F);
        else {
            value = max(knapsack(i - 1, j, w, v, F), v[i] + knapsack(i - 1, j - w[i], w, v, F));   
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main(){
    ll s, n, peso, valor;
    cin >> s >> n;

    vector<vector<ll>> F(n + 1, vector<ll>(s + 1, -1));

    for (int i = 0; i <= s; i++){
        F[0][i] = 0;
    }
    for (int i = 0; i <=n; i++){
        F[i][0] = 0;
    }

    ll v[n + 1];
    ll w[n + 1];

    v[0] = -1;
    w[0] = -1;

    for(int i = 1; i < n; i++){
        cin >> peso >> valor;
        w[i] = peso;
        v[i] = valor;
    }

    cout << knapsack(n, s, w, v, F) << endl;

    return 0;
}