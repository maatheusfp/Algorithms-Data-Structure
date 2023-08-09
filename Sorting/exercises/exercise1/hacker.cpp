#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int array[], int l, int m, int r){
    int i, j, k;
    int leftLength = m - l + 1;
    int rightLength = r - m;

    int tempLeft[leftLength];
    int tempRight[rightLength];

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

void mergesort(int array[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

int binarySearch(int array[], int size, int key){
    int l = 0;
    int r = size - 1;

    while (l <= r){
        int m = (l + r)/2;
        if (key == array[m]){
            return 1;
        } 
        else if (key < array[m]){
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return 0;
}

int main(){
    int n, k;
    int pares = 0;
    cin >> n >> k;
    int array[n];

    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    mergesort(array, 0, n);
    for (int j = 0; j < n; j++){
        int result = binarySearch(array, n, array[j] + k);
        if (result == 1){
            pares++;
        }
    
    }
        
    cout << pares << endl;

    return 0;
}