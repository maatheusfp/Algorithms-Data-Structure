#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct heap{
    int *arr;
    int count;
    int capacity;
    int heap_type; 
} Heap;

Heap *CreateHeap(int capacity,int heap_type){
    Heap *h = (Heap * ) malloc(sizeof(Heap)); 
    h->heap_type = heap_type;
    h->count=0;
    h->capacity = capacity;
    h->arr = (int *) malloc(capacity*sizeof(int));
    return h;
}

void heapify_bottom_top(Heap *h,int index){
    int temp;
    int parent_node = (index-1)/2;

    if(h->arr[parent_node] > h->arr[index]){
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h,parent_node);
    }
}

void heapify_top_bottom(Heap *h, int parent_node){
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != parent_node){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;
        heapify_top_bottom(h, min);
    }
}

void insert(Heap *h, int key){
    if( h->count < h->capacity){
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

int PopMin(Heap *h){
    int pop;
    if(h->count==0){
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}

int main(){
    int a, b;
    int n = 1;
    int num;

    while(cin >> n && n){
        Heap *heap = CreateHeap(n, 0);
        for (int i = 0; i < n; i++){
            cin >> num;
            insert(heap, num);
        }

        long long int ans = 0;

        while (heap->count > 1){
            a = PopMin(heap);
            b = PopMin(heap);
            ans += (a + b);
            insert(heap, a + b);
        }
        cout << ans << endl;
    }                       
    return 0;                                         
}
    
