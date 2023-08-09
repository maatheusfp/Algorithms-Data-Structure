#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(long long array[], int l, int r){
    int temp[l + r + 1];
    for (int i = l; i <= r; i++){
        temp[i] = array[i];
    }

    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;

    for (int curr = l; curr <= r; curr++){
        if (i1 == (m + 1)){
            array[curr] = temp[i2++];
        }
        else if (i2 > r) {
            array[curr] = temp[i1++];
        }
        else if (temp[i1] <= temp[i2]){
            array[curr] = temp[i1++];
        }
        else {
            array[curr] = temp[i2++];
        }
    }

}
void mergesort(long long array[], int l, int r){
    if (l < r){
        int m = (l + r)/2;
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, r);
    }
} 

int main(){
    int n, q, x, y, i;
    long long soma;
    cin >> n >> q;
    long long array[n + 1];
    array[0] = 0;

    for (int j = 0; j < n; j++){
        cin >> array[j + 1];
    }

    mergesort(array, 0, n);

    for (int j = 1; j <= n; j++){
        array[j] += array[j - 1]; 
    }

    while (q--){
        cin >> x >> y;

        cout << (array[n + y - x] - array[n - x]) << endl;
    }

    return 0;
}