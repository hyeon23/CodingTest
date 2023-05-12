#include <iostream>

using namespace std;

int main(){
    int* arr;
    int N, M, i, j, k;

    cin >> N >> M;

    arr = new int[N + 1];

    for(int i1 = 1; i1 <= N + 1; ++i1){
        arr[i1] = i1;
    }

    for(int i1 = 0; i1 < M; ++i1){
        cin >> i >> j >> k;

        int* arr2 = new int[N + 1];

        for(int i = 1; i <= N; ++i){
            arr2[i] = arr[i];
        }

        int count = 0;
        
        for(int i2 = i; i2 <= j; ++i2){
            arr[i2] = arr2[(k + count) % (j - i + 1)];

            count++;
        }
    }

    for(int i = 0; i < N; ++i){
        cout << arr[i] << " ";
    }

    return 0;
}