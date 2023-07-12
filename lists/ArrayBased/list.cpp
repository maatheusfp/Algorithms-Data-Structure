#include <iostream>
#include "list.h"
using namespace std;

typedef struct list {
    int maxSize, listSize, curr;
    int* listArray;
} List;

List* create_list(int size){
    List* l = (List*) malloc(sizeof(List));
    l -> maxSize = size;
    l -> listSize = l -> curr = 0;
    l -> listArray = (int*) malloc(size*(sizeof(int)));
    return l;
}

void clear(List* l){
    free(l->listArray);
    free(l);
}

void insert(List* l, int it){
    if (l->listSize >= l->maxSize){
        cout << "erro" << endl;
    }
    else {
        int i = l->listSize;
        while (i > l->curr){
            l->listArray[i] = l->listArray[i - 1];
            i--;
        }
        l->listArray[l->curr] = it;
        l->listSize++;
    }
}

void moveToStart(List* l){
    l->curr = 0;
}

void moveToEnd(List* l){
    l->curr = l->listSize;
}

void prev(List* l){
    if (l->curr != 0){
        l->curr--;
    }
}

void next(List* l){
    if (l->curr < l->listSize){
        l->curr++;
    }
}

int remove(List* l){
    if (l->curr < 0 || l->curr >= l->listSize){
        return 0;
    } 
    int it = l->listArray[l->curr];
    int i = l->curr;

    while (i < l->listSize - 1){
        l->listArray[i] = l->listArray[i + 1];
        i++;
    }

    l->listSize--;
    return it;
}

int count(List* l, int n){
    int count;
    for (int i = 0; i < l->listSize; i++){
        if (l->listArray[i] == n){
            count++;
        }
    }
    return count;
}

void print(List* l){
    for (int j = 0; j < l->listSize; j++){
        cout << l->listArray[j] << " ";
}
}