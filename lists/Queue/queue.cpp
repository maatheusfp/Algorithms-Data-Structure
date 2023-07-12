#include <iostream>
using namespace std;

typedef struct link{
    int element;
    link* next;
} Link;

typedef struct queue{
    Link* front;
    Link* rear;
    int size;
} Queue;

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

Queue* create_queue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = create_link(NULL);
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue* q){
    if (q->size == 0){
        return -1;
    }
    else {
        int it = q->front->next->element;
        q->front->next = q->front->next->next;
        
        if(q->front->next == NULL){
            q->rear = q->front;
        }
        q->size--;
    }
}

int main(){

    return 0;
}