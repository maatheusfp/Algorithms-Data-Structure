#include <iostream>
#include <stdlib.h>

using namespace std;

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

    int c;
    cin >> c;

    for (int m = 0; m < c; m++){
        int n;
        cin >> n;
        int array[n];

        for (int k = 0; k < n; k++){
            cin >> array[k];
        }

        quicksort(array, 0, n);

        for (int  i=0; i < n; i++){
            printf("%d ", array[i]);
        }
    }

    return 0;
}