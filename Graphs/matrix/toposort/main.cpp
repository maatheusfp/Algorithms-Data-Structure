#include <iostream>
#include <stack>
using namespace std;

typedef struct graph {
    int** matrix;
    int numEdge, size;
    int* mark;
    stack<int> s;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->mark = new int[n];
    g->matrix = new int*[n];
    for (int i = 0; i < n; i++) g->matrix[i] = new int[n];
    g->numEdge = 0;
    g->size = n;
    return g;
}

int first(Graph* g, int v){
    for (int i = 0; i < g->size; i++){
        if (g->matrix[v][i] != 0) return i;
    }
    return g->size;
}

int next(Graph* g, int v, int w){
    for (int i = w + 1; i < g->size; i++){
        if (g->matrix[v][i] != 0) return i;
    }
    return g->size;
}

void addEdge(Graph* g, int i, int j){
    if (g->matrix[i][j] == 1) return;
    if (g->matrix[i][j] == 0) g->numEdge++;
    g->matrix[i][j] = 1;
}

void setMark(Graph* g, int v, int visit){
    g->mark[v] = visit;
}

int getMark(Graph* g, int v){
    return g->mark[v];
}

void toposort(Graph* g, int v){
    setMark(g, v, 1);
    int w = first(g, v);
    while (w < g->size){
        if (getMark(g, w) == 0) toposort(g, w);
        w = next(g, v, w);
    }
    g->s.push(v);
}

void graphTraverse(graph* g){
    for (int v = 0; v < g->size; v++) setMark(g, v, 0);
    for (int v = 0; v < g->size; v++){
        if (getMark(g, v) == 0) toposort(g, v);
    }
    int size = g->s.size();
    for (int i = 0; i < size; i++){
        int last = g->s.top();
        cout << last << " ";
        g->s.pop();
    }
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    Graph* g = create_graph(n);

    while (m--){
        cin >> u >> v;
        addEdge(g, u, v);
    }
    graphTraverse(g);
    return 0;
}