#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

typedef struct {
    string nome;
    double sec;
} Competitor;

void merge(Competitor array[], int l, int m, int r){
    int i, j, k;
    int leftLength = m - l + 1;
    int rightLength = r - m;

    Competitor tempLeft[leftLength];
    Competitor tempRight[rightLength];

    for (int i = 0; i < leftLength; i++)
        tempLeft[i] = array[l + i];

    for (int j = 0; j < rightLength; j++)
        tempRight[j] = array[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;

    while (i < leftLength && j < rightLength) {
        if (tempLeft[i].sec < tempRight[j].sec) {
            array[k] = tempLeft[i];
            i++;
        }
        else if (tempLeft[i].sec > tempRight[j].sec){
            array[k] = tempRight[j];
            j++;
        }
        else {
            if (tempLeft[i].nome < tempRight[j].nome){
                array[k] = tempLeft[i];
                i++;
            }
            else {
                array[k] = tempRight[j];
                j++;
            }
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

void mergesort(Competitor array[], int l, int r){
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
    Competitor competitors[c];

    for (int i = 0; i < c; i++){
        cin >> competitors[i].nome >> competitors[i].sec;
    }

    mergesort(competitors, 0, c - 1);

    for (int i = 0; i < c; i++){
        cout << competitors[i].nome << " " << competitors[i].sec << endl;
    }
    return 0;   
}