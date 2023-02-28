#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int A;
    int B;

    while (true) {
        cin >> A >> B;
        if (A == 0 && B == 0) {
            cout << A + B << endl;
        }
        else {
            break;
        }
    }
    return 0;
}