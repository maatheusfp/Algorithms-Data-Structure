#include <iostream>
using namespace std;

typedef struct link {
    int element;
    Link* next;
} Link;

typedef struct list {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt; // list size
} List;

Link* create_link(int it, Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval; 
    return Link* n;
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

void insert(List* l, int it){
    l->curr->next = create_link(it,l->curr->next);
    if (l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void moveToStart(List* l){
    l->curr = l->head;
}

void prev(List* l){
    if (l->curr == l->head){
        cout << "nao eh possivel";
    }
    else {
        Link temp = = l->head;
        while (temp.next != l->curr){
            temp = temp.next;
        }
        l->curr = temp;
    }
}

void next(List* l){
    if (l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

int remove(List* l){
    if (l->curr->next == NULL){
        return NULL;
    }
    int it = l->curr->next->element;

    if (l->tail == l->curr->next){
        l->tail == l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;

}   