#include <iostream>
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

typedef struct dict {
    int m;
    int cnt;
    List* H;
    //  h : Key -> 0 
} Dict;



int h(int K){
    // create the hash function in here depending on the mecanism
}



int main(){

    return 0;
}
