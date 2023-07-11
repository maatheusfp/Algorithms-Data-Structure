#include <iostream>
#include <string>
#include "list.h"
using namespace std;

int main(){
    int c, n, numero;
    string comando;
    cin >> c;

    while (c--){
        cin >> n;
        List* l = create_list(1000);

        for (int i = 1; i <= n; i++){
            cout << "Caso" << " " << i << endl;
            cin >> comando;
            if (comando == "insert"){
                cin >> numero;
                insert(l, numero);

            }
            else if (comando == "count"){
                cin >> numero;
            
            }
            else {
                if (comando == "remove"){
                    remove(l);
                }
                else if (comando == "prev"){
                    prev(l);
                }
                else if (comando == "next"){
                    next(l);
                }
                else {
                    cout << "comando invalido" << endl;
                }
            }
        }
    }

    return 0;
}