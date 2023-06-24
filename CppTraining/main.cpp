#include <iostream>

using namespace std;

int main (){

        long int n, m, a, flagstoneN, flagstoneM;

        cin >> n >> m >> a;

        flagstoneN = n / a;
        
        if ((n % a) > 0) flagstoneN++;

        flagstoneM = m / a;

        if ((m % a) > 0) flagstoneM++;

        cout << flagstoneN * flagstoneM << endl;

    return 0;
}