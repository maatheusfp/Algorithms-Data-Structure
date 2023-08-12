#include <iostream>
#include <string.h>
using namespace std;

typedef struct link {
    char element;
    link* next;
} Link;

typedef struct list {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
} List;


Link* create_link(char it, Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval; 
    return n;
}

Link* create_link(Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n->next = nextval;
    return n;
}

List* create_list(){
    List* l = (List*) malloc(sizeof(List));
    l->curr = l->tail = l->head = create_link(NULL);
    l->cnt = 0;
    return l;
}

void next(List* l){
    if (l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

void insert(List* l, char it){
    l->curr->next = create_link(it,l->curr->next);
    if (l->tail == l->curr){
        l->tail = l->curr->next;
    }
    next(l);
    l->cnt++;
}

void moveToStart(List* l){
    l->curr = l->head;
}

void moveToEnd(List* l){
    l->curr = l->tail;
}

void print(List* l){
    moveToStart(l);
    while (l->curr->next != NULL){
        cout << l->curr->next->element;
        l->curr->next = l->curr->next->next;
    }
    cout << endl;
}

int main(){
    char text[100001];
    while (cin >> text){
         
        int size = strlen(text);

        List* l = create_list();

        for (int i = 0; i < size; i++){
            if (text[i] == '[') {
                moveToStart(l);
            }
            else if (text[i] == ']') {
                moveToEnd(l);
            }
            else {
                insert(l, text[i]);
            }
        }
        print(l);
    }
}