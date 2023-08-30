#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y;
    int in[10001] = {0};
    vector<int> road;
    vector<vector<int>> adjlist(10001);
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        adjlist[x].push_back(y);
        in[y]++;
    }

    for (int i = 1; i <= n; i++){
        if (!in[i]) q.push(i);
    }

    while (!q.empty()){
        int v = q.top();
        q.pop();
        road.push_back(v);

        for (auto i(adjlist[v].begin()); i != adjlist[v].end(); i++){
            if (--in[*i] == 0) q.push(*i);
        }
    }

    if (road.size() < n) {
        cout << "Sandro" << " " << "fails.";
    }
    else {
        for (int j = 0; j < road.size(); j++){
            cout << road[j] << " ";
        }
    }
    cout << endl;
    return 0;
}   