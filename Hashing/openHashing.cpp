#include <iostream>
#include <string.h>
using namespace std;

int h(String K){
    int length = strlen(K)/4;// look for some way to calculate the length without the built-in function
    int sum = 0;
    for (int i = 0; i < length; i++){
        sub = substring(K, i*4, (i*4) + 4); // What's this function??
        int mult = 1;
        for (int j = 0; j <= 3; j++){
            sum += sub[j] * mult;
            mult *= 256;
        }
    }

    sub = substring(K, length*4);
    int mult = 1;
    s = length(sub);
    for (int j = 0; j < s; j++){
        sum += sub[j]*mult;
        mult *= 256;
    }

    return abs(sum)%m; // absolute value function
}

int main(){

    return 0;
}