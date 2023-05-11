#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int T = 0;
    int A = 0;
    int B = 0;

    cin >> T;

    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &A, &B);
        int C = A + B;
        printf("Case #%d: %d + %d = %d\n", i, A, B, C);

        //cin >> A >> B;
        //cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << endl;
    }

    return 0;
}