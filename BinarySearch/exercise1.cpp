#include <iostream>
#include <stdlib.h>

using namespace std;

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

int main() {
    int array[8] = {29, 30, 45, 67, 98, 102, 200, 304};
    int key, result;
    cin >> key;

    result = binarySearch(array, 8, key);

    if (result > 0){
        cout << "tem" << endl;
    }
    else{
        cout << "nao tem" << endl;
    }

    return 0;
}