#include <iostream>
#include <stdlib.h>

using namespace std;

int partition(int array[], int l, int r){
    int x, i, aux;
    x = array[r];
    i = l - 1;

    for (int j = l; j <= r - 1; j++){
        if (array[j] > x){
            i++;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    aux = array[i + 1];
    array[i + 1] = array[r];
    array[r] = aux;

    return i + 1;
}

void quicksort(int array[], int l, int r){
    int pos;

    if (l < r){
        pos = partition(array, l, r);
        quicksort(array, l, pos - 1);
        quicksort(array,pos + 1, r); 
    }
}

int main(){

    int n;
    cin >> n;
    int array1[n];

    for (int k = 0; k < n; k++){
        cin >> array1[k];
    }

    quicksort(array1, 0, n);

    for (int i = 0; i < n; i++){
        printf("%d ", array1[i]);
    }

    return 0;
}