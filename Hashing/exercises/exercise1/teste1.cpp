#include <iostream>
#include <string>
using namespace std;

struct MyHashMap {
    string values[101];

    void initialize() {
        for (int i = 0; i < 101; i++) {
            values[i] = "";
        }
    }

    bool insert(string item) {
        int h, hash, new_hash;
        h = 0;
        for (int i = 0; i < item.length(); i++) {
            h += int(item[i]) * (i + 1);
        }
        hash = (h * 19) % 101;

        if (values[hash] == item) {
            return false;
        } else {
            for (int j = 1; j <= 19; j++) {
                new_hash = (hash + (23 * j) + (j * j)) % 101;
                if (values[new_hash] == item) {
                    return false;
                }
            }
        }

        if (values[hash] == "") {
            values[hash] = item;
            return true;
        }

        for (int j = 1; j <= 19; j++) {
            new_hash = (hash + (j * j) + (23 * j)) % 101;
            if (values[new_hash] == "") {
                values[new_hash] = item;
                return true;
            }
        }
        return false;
    }

    bool remove(string item) {
        for (int i = 0; i < 101; i++) {
            if (values[i] == item) {
                values[i] = "";
                return true;
            }
        }
        return false;
    }
};

int main() {
    int numTestCases, numOperations, entryCount;
    string operation, item;

    cin >> numTestCases;
    for (int tCase = 0; tCase < numTestCases; tCase++) {
        cin >> numOperations;
        entryCount = 0;

        MyHashMap myMap;
        myMap.initialize();

        for (int opIdx = 0; opIdx < numOperations; opIdx++) {
            cin >> operation;
            if (operation.substr(0, 3) == "ADD") {
                item = operation.substr(4);
                if (myMap.insert(item)) {
                    entryCount += 1;
                }
            } else if (operation.substr(0, 3) == "DEL") {
                item = operation.substr(4);
                if (myMap.remove(item)) {
                    entryCount -= 1;
                }
            }
        }

        cout << entryCount << "\n";
        for (int i = 0; i < 101; i++) {
            if (myMap.values[i] != "") {
                cout << i << ":" << myMap.values[i] << "\n";
            }
        }
    }
    return 0;
}