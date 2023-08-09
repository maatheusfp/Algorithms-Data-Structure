#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int array[], int l, int m, int r){
    int i, j, k;
    int leftLength = m - l + 1;
    int rightLength = r - m;

    int tempLeft[leftLength];
    int tempRight[rightLength];

    for (int i=0; i < leftLength; i++)
        tempLeft[i] = array[l + i];

    for (int j=0; j < rightLength; j++)
        tempRight[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = 0;

    while (i < leftLength && j < rightLength){
        if (tempLeft[i] <= tempRight[j]){
            array[k] = tempLeft[i]
            i++;
        }
        else {
            array[k] = tempRight[j];
            j++;
        }
        k++;
    } 

    while (i < leftLength){
        array[k] = tempLeft[i];
        i++;
        k++;
    }

    while (j < rightLength){
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

int main() {

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        int array[n];

        for (int m = 0; m < n; m++)
            cin >> array[m];

        mergesort(array, 0, n - 1);

        for (int l = 0; l < n; l++)
            cout << array[l] << " ";
            cout << endl;
    }

    return 0;
}