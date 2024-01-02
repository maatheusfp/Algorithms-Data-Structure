#include <string.h>
#include <iostream>
using namespace std;

typedef struct list {
    int maxSize, listSize, curr;
    char* listArray;
} List;

List* create_list(int size){
    List* l = (List*) malloc(sizeof(List));
    l -> maxSize = size;
    l -> listSize = l -> curr = 0;
    l -> listArray = (char*) malloc(size*(sizeof(char)));
    return l;
}

void moveToStart(List* l){
    l->curr = 0;
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

bool search(List* l){

    int sequence = 0;
    bool find = false;

    if (l->listSize > 2 && l->curr > 2) l->curr -= 2;
    else moveToStart(l);

    while (!find && l->curr < l->listSize){
        if (l->listArray[l->curr] == 'A') sequence = 1;
        else if (l->listArray[l->curr] == 'B') {
            if (sequence == 1) sequence++;
            else sequence = 0;
        } 
        else if (l->listArray[l->curr] == 'C' && sequence == 2) find = true;
        l->curr++; 
    }

    return find;
}

int main() {
    bool found = true;
    char string[200001];

    cin >> string;
    int size = strlen(string);

    List* l = create_list(200001);
    l->listSize = size;

    for (int i = 0; i < size; i++){
        l->listArray[i] = string[i];
    }

    while (found){
        bool find = search(l);
        if (find){
            l->curr -= 3;
            remove(l);
            remove(l);
            remove(l);
        }
        else found = false;
    }

    if (l->listSize > 0){
        for (int i = 0; i < l->listSize; i++) cout << l->listArray[i];
    }
    else cout << endl;
    
    return 0; 
}