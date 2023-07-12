#include <iostream>
#include <string>
using namespace std;

typedef struct link {
    int element;
    link* next;
} Link;

typedef struct list {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
} List;

Link* create_link(int it, Link* nextval){
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
        Link* temp = l->head;
        while (temp->next != l->curr){
            temp = temp->next;
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
        return -1;
    }
    int it = l->curr->next->element;

    if (l->tail == l->curr->next){
        l->tail == l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;
}   

int count(List* l, int num){
    int contador = 0;
    Link* temp = l->head;
    while (temp->next != NULL){
        if (temp->next->element == num){
            contador++;
        }
        temp = temp->next;
    }
    return contador;
}

/* void clear(List* l){
    free()
} */

int main(){
    int c, n;
    cin >> c;
    string comando;

    for (int i = 1; i <= c; i++){
        cout << "Caso" << " " << i << endl;
        cin >> n;
        List* l = create_list();

        for (int j = 0; j < n; j++){
            int numero;
            cin >> comando;
            if (comando == "insert"){
                cin >> numero;
                insert(l, numero);
            }
            else if (comando == "count"){
                int qtd;
                cin >> numero;
                qtd = count(l, numero);
                cout << qtd << endl;
            }
            else {
                if (comando == "remove"){
                    remove(l);
                }
                else if (comando == "prev"){
                    prev(l);
                }
                else if (comando == "next"){
                    next(l);
                }
            }
        } 
    }

    return 0;
}