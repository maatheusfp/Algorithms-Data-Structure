#include <iostream>
using namespace std;

typedef struct link {
    int element;
    link* next;
} Link;

typedef struct stack{
    Link* top;
    int size;
} Stack; 

typedef struct dict{
    int m, cnt;
    Stack* H;
} Dict;

Link* create_link(int it, Link* nextval){
    Link* n = (Link*) malloc(Link);
    n->element = it;
    n->next = nextval;
    return n;
}

Stack* create_stack(){
    Stack* s = (Stack*) malloc(Stack);
    s->top = NULL;
    s->size = 0;
    return l;
}

int h(int k){
    return abs(k) % 10;
}

int find(Dict* d, int value){
    int pos = h(value);
    
}

void append(Stack* s, int it){
    s->top = create_link(it, l->top);
    s->size;
}

Dict* create_dict(int size){
    Dict* d = (Dict*) malloc(Dict);
    d->m = size;
    d->cnt = 0;
    d->H = new Stack[size];
    for (int i = 0; i < size; i++){
        d->H[i] = create_stack();
    }
    return d;
}

int main(){

    return 0;
}
