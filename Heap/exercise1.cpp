#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int array[], int l, int r){
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
void mergesort(int array[], int l, int r){
    if (l < r){
        int m = (l + r)/2;
        mergesort(array, l, m);
        mergesort(array, m + 1, r);
        merge(array, l, r);
    }
} 

int main(){
    int n, a, b;

    while (n != 0){
        cin >> n;
        if (n == 0) return 0;
        int array[n];
        
        for (int i = 0; i < n; i++){
            cin >> array[i];
        }
        mergesort(array, 0, n - 1);
        
        int j = 0;
        long long int ans = 0;
        while (j < n - 1){
            a = array[j];
            array[j] = 0;
            j++;

            b = array[j];
            ans += (a + b);
            array[j] = a + b;
        }

        cout << ans << endl;
    }
    return 0;
}