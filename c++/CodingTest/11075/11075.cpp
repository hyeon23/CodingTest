#include <iostream>

using namespace std;

#define MOD 10007

int main()
{
    int N;
    int sum = 0;
    int arr[1001][10] = { 0, };

    cin >> N;

    for (int i = 0; i < 10; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }

            arr[i][j] %= MOD;
        }
    }

    for (int i = 0; i < 10; i++) {
        sum += arr[N][i];
    }

    sum %= MOD;

    cout << sum << endl;

    return 0;
}
