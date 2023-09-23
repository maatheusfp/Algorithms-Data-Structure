#include <bits/stdc++.h>
using namespace std;

#define pp pair<int, int>

int Dijkstra(int origem, int destino, int n, vector<pp> graph[]){
    vector<int> dist (n, 100000001);
    priority_queue<pp, vector<pp>, greater<pp>> heap;
    dist[origem] = 0;
    heap.push(make_pair(dist[origem], origem));

    while (!heap.empty()){
        int vertice = heap.top().second;
        int d = heap.top().first;
        heap.pop();

        if (d > dist[vertice]) continue;

        for (auto vertex : graph[vertice]){
            int w = vertex.first;
            int v = vertex.second;

            if (dist[v] > dist[vertice] + w){
                dist[v] = dist[vertice] + w;
                heap.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[destino]; 
}

int main(){
    int n, m, u, v, length, city1, city2;
    cin >> n >> m;
    vector<pp> graph[n];

    while(m--){
        cin >> u >> v >> length;
        graph[u].push_back(make_pair(length, v));
        graph[v].push_back(make_pair(length, u));
    }

    while (city1 != 0 || city2 != 0){
        cin >> city1 >> city2;

        int range = Dijkstra(city1, city2, n, graph);

        if (range > 100000000 || range < 1) cout << "IMPOSSIBLE" << endl; 
        else {
            cout << range << endl;
        }
    }
    return 0;
}