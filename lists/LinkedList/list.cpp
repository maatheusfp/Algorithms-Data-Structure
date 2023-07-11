#include <iostream>
using namespace std;

typedef struct link {
    int element;
    Link next;
} Link;

Link create_link(int it, Link nextval){
    n->element = it;
    n->next = nextval; 
    return n;
}

typedef struct list {
    Link head;
    Link tail;
    Link curr;
    int cnt; // list size
} List;

List create_list(){
    l->curr = l->tail = l->head = create_link(NULL);
    l->cnt = 0;
    return l;
}