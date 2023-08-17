#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef struct graph{
    int** matrix;
    int numEdge, size;
    int* mark;
    int* path;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->mark = new int[n];
    g->matrix = new int*[n];
    g->path = new int[n];
    for (int i = 0; i < n; i++){
        g->matrix[i] = new int[n];
    }
    g->numEdge = 0;
    g->size = n;
    return g;
}

void setMark(Graph* g, int v, int mark){
    g->mark[v] = mark;
}

int getMark(Graph* g, int v){
    return g->mark[v];
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
    if (g->matrix[i][j] == 1 || g->matrix[j][i] == 1){
        return;
    }
    g->numEdge++;
    g->matrix[i][j] = 1;
    g->matrix[j][i] = 1;
}

void BFS(Graph* g, int start, int destiny){
    queue<int> q;
    bool found = false;
    q.push(start);
    setMark(g, start, 1);

    while (q.size() > 0 && found == false){
        int v = q.front();
        if (v == destiny) found = true;
        else {
            q.pop();
            g->path[v] += 1;
            int w = first(g, v);

            while(w < g->size){
                if (getMark(g, w) == 0){
                    setMark(g, w, 1);
                    q.push(w);
                }

                w = next(g, v, w);
            }
        }
    }
}

void graphTraverseBFS(Graph* g, int start){
    for (int v = 0; v < g->size; v++){
        setMark(g, v, 0);
        g->path[v] = 0;
    }
    for (int v = 0; v < g->size; v++){
        if (getMark(g, v) == 0) BFS(g, start, v);
    }
}