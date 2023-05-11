#include <iostream>

using namespace std;

int main() {
    int A;
    int B;

    //sol1
    //while (!(cin >> A >> B).eof()) {
    //    cout << A + B << endl;
    //}

    //sol2
    while (cin >> A >> B) {
        cout << A + B << endl;
    }
    return 0;
}