#include <iostream>
#include <stdlib.h>

using namespace std;

int paritition(int array, int l, int r){
    int p, i, j, aux;

    p = array[l];
    i = l;
    j = r + 1;

    do {
        do {
            i++;
        } while (array[i] < p);

        do {
            j++;
        } while (array[j] > p);
        aux = array[i];
        array[i] = array[j];
        arrayj[j] = aux;
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

int main() {

    int array[5] = {1, 5, 4, 3, 2};

    quicksort(array, 0, 5)

    return 0;
}