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
    s->top = create_link(it, s->top); // add E it to the top 
    s->size++;
}

int pop(Stack* s){
    if (s->top == NULL){
        cout << "error" << endl;
    }
    else {
        int it = s->top->element;
        s->top = s->top->next;
        s->size--;
        return it;
    }
}

int sum(Stack* s, int num){
    int count = 0;
    int aux;
    while(num--){
        aux = pop(s);
        count += aux;
    }
    return count;
}

int main(){
    int c, numero, soma;
    string comando;
    cin >> c;

    for (int i = 1;i <= c;i++){
        cout << "Caso" << " " << i << ":" << endl;

        while (comando != "end"){
            cin >> comando >> numero;

            Stack* s = create_stack();

            if (comando == "push"){
                push(s, numero);
            }
            else if (comando == "pop"){
                soma = sum(s, numero);
                cout << soma << endl;
            }
        }   
    }
    
    return 0;
}