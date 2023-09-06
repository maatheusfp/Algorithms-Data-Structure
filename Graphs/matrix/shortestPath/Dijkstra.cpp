#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

long long int Dijkstra(int start, int n, vector<pp> graph){
    vector <long long int> dist(n, 500000001);
    priority_queue<pp, vector<pp>, greater<pp>> heap;
    dist[start] = 0;
    heap.push(make_pair(dist[start], start));

    while(!heap.empty()){
        int u = heap.top().second; // aresta
        long long int d = heap.top().first; // distancia
        heap.pop();

        if (d > dist[u]) continue; // adiantar

        for (auto edge : graph[u]){
            int w = edge.first;
            int v = edge.second;

            if (dist[v] > dist[u] + w)
        }
    }
}


int main(){
    return 0;
}