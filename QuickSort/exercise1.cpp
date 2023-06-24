#include <iostream>
#include <stdlib.h>

int partition(int array[], int l, int r){
    int p, i, j, aux;

    p = array[l];
    i = l;
    j = r + 1;

    do {
        do {
            i++ ;
        } while (array[i] < p);

        do {
            j--;
        } while (array[j] > p);
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    } while (i < j);

    aux = array[i];
    array[i] = array[j];
    array[j] = aux;

    aux = array[l];
    array[l] = array[j];
    array[j] = aux;

    return j;
}

void quicksort(int array[], int l, int r){
    int pos;

    if (l < r){
        pos = partition(array, l, r);
        quicksort(array, l, pos - 1);
        quicksort(array, pos + 1, r);
    }
}

int main(){

    int array1[7] = {84, 1, 6, 48, 48, 12, 3};
    int n = 7;

    quicksort(array1, 0, n);

    printf("\n\n\n");

    for (int i=0; i < n; i++){
        printf("%d ", array1[i]);
    }

    printf("\n\n\n");

    return 0;
}