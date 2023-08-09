#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(long long array[], int l, int m, int r){
    int i, j, k;
    int leftLength = m - l + 1;
    int rightLength = r - m;

    long long tempLeft[leftLength];
    long long tempRight[rightLength];

    for (int i = 0; i < leftLength; i++)
        tempLeft[i] = array[l + i];

    for (int j = 0; j < rightLength; j++)
        tempRight[j] = array[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;

    while (i < leftLength && j < rightLength) {
        if (tempLeft[i] <= tempRight[j]) {
            array[k] = tempLeft[i];
            i++;
        }
        else {
            array[k] = tempRight[j];
            j++;
        }
        k++;
    }

    while (i < leftLength) {
        array[k] = tempLeft[i];
        i++;
        k++;
    }

    while (j < rightLength) {
        array[k] = tempRight[j];
        j++;
        k++;
    }
}

void mergesort(long long array[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

int main(){
    int n, q, x, y, i;
    long long soma;
    cin >> n >> q;
    long long array[n];

    for (int j = 0; j < n; j++){
        cin >> array[j];
    }

    mergesort(array, 0, n - 1);

    while (q--){
        cin >> x >> y;

        soma = 0;
        i = n - x;

        while (y > 0){
            soma += array[i];
            i++;
            y--;
        }

        cout << soma << endl;
    }

    return 0;
}