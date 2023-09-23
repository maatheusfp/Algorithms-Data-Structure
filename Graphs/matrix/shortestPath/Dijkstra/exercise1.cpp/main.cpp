#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

long long int Dijkstra(int start, int destiny, int n, vector<pp> graph[]){
    vector <long long int> dist(n, 500000001);
    priority_queue<pp, vector<pp>, greater<pp>> heap;
    dist[start] = 0;
    heap.push(make_pair(dist[start], start));

    while(!heap.empty()){
        int u = heap.top().second; // vértice
        long long int d = heap.top().first; // distancia
        heap.pop();

        if (d > dist[u]) continue; // adiantar

        for (auto edge : graph[u]){
            int w = edge.first;
            int v = edge.second;

            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                heap.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[destiny];
}

int main(){
    int cases, n, m, s, t, u, v, w;
    cin >> cases;
    
    for (int i = 1; i <= cases; i++){
        cin >> n >> m >> s >> t;
        vector<pp> graph[n];
        while (m--){
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(w, v));
            graph[v].push_back(make_pair(w, u)); // nao direcionado
        }
        long long int result = Dijkstra(s, t, n, graph);
        if (result < 500000001){
            cout << "Case" << " " << "#" << i << ":" << " " << result << endl;
        }
        else {
            cout << "Case" << " " << "#" << i << ":" << " " << "unreachable" << endl;
        }
    }
    return 0;
}