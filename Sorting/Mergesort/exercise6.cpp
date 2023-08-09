#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

typedef struct {
    string name;
    double sec;
} Competitor;

int main(){

    int c; 
    cin >> c;

    Competitor competitors[c];

    for (int i = 0; i < c; i++)
        cin >> competitors[i].name >> competitors[i].sec;

    mergesort(competitors, 0, c -1);
    
    return 0;
}