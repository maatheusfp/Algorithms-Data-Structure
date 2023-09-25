#include <bits/stdc++.h>
using namespace std;

#define pp pair<int, int>

const int inf = 0x3f3f3f3f;

vector<int> Prim(int n, vector<pp> graph[]){

    vector<int> dist (n, inf);
    vector<bool> visited(n, false);
    priority_queue<pp, vector<pp>, greater<pp>> heap;
    dist[0] = 0;
    heap.push(make_pair(dist[0], 0));

    while (!heap.empty()){
        int vertice = heap.top().second;
        int d = heap.top().first;
        heap.pop();

        if(visited[vertice]) continue;
        visited[vertice] = true;

        for (auto vertex : graph[vertice]){
            int w = vertex.first;
            int v = vertex.second;

            if (dist[v] > w && !visited[v]){
                dist[v] = w;
                heap.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;

}

int main(){
    int n, m, u, v, length, city1, city2;

    while(cin >> n >> m && n){

        vector<pp> graph[n+10];

        while(m--){
            cin >> u >> v >> length;
            graph[u].push_back(make_pair(length, v));
            graph[v].push_back(make_pair(length, u));
        }

        vector<int> dist = Prim(n, graph);

        bool impossible = false;

        int maiorzao = -inf;

        for(int currentdist: dist){
            if(currentdist == inf){
                impossible = true;
                break;
            } else {
                maiorzao = max(maiorzao, currentdist);
            }
        }

        if(impossible) cout << "IMPOSSIBLE" << endl;
        else cout << maiorzao << endl;


    }

}