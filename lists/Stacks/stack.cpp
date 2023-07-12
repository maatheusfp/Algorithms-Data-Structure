#include <iostream>
using namespace std;

typedef struct link{
    int element;
    link* next;
} Link;

typedef struct stack {
    Link* top;
    int size;
} Stack;

Link* create_link(int it, Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    retun n;
}