#include <iostream>

using namespace std;

int main() {
    int A;
    int B;
    while (!(cin >> A >> B).eof()) {
        cout << A + B << endl;
    }
    return 0;
}