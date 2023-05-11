#include <stdio.h>

int main() {
    int T = 0;
    int A = 0;
    int B = 0;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &A, &B);
        int sum = A + B;
        printf("Case #%d: %d\n", i, sum);

        /*cin >> A >> B;
        cout << "Case #" << i << ": " << A + B << endl;*/
    }

    return 0;
}