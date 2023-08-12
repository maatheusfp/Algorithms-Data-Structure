#include <iostream>
#include <string>
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
    return n;
}

Stack* create_stack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack* s, int it){
    s->top = create_link(it, s->top);
    s->size++;
}

void pop(Stack* s){
    if (s->top == NULL){
        cout << "error" << endl;
    }
    else {
        int it = s->top->element;
        s->top = s->top->next;
        s->size--;
    }
}

int main(){
    int n, x;
    while(cin >> n && n){

        while(cin >> x && x){
            int cur = 1;
            bool pass = true;
            Stack* s = create_stack();

            for(int i = 1; i < n; i++){
                for(;cur <= x; cur++) push(s, cur);
                if (s->top->element != x) pass = false;
                pop(s);
                cin >> x;
            }
            if(pass){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
}