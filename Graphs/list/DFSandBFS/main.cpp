#include <iostream>
#include <list>
#include <string.h>
using namespace std;

typedef struct graph{
    list<int> *adjList;
    int numEdge, size;
    int* mark;
} Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->mark = new int[n];
    g->adjList = new list<int>[n];
    g->numEdge = 0;
    g->size = n;
}

void addEdge(Graph* g, int i, int j){
    g->adjList[i].push_front(j);
    g->adjList[j].push_front(i); // undirect graph
    g->numEdge++;
}