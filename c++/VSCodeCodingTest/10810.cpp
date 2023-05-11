#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // vector<int> vec;
    // int N, M;
    // cin >> N >> M;

    // int i, j, k;

    // for(int jj = 0; jj < N; ++jj){
    //     vec.push_back(0);
    // }

    // for(int a = 0; a < M; ++a){
    //     cin >> i >> j >> k;

    //     for(int ii = i; ii <= j; ++ii){
    //         vec[ii-1] = k;
    //     }
    // }

    // for(int kk = 0; kk < N - 1; ++kk){
    //     cout << vec[kk] << " ";
    // }

    // cout << vec[N-1];

    int *arr;
    int N, M;
    cin >> N >> M;

    arr= new int[N];

    int i, j, k;

    for (int jj = 0; jj < N; ++jj)
    {
        arr[jj] = 0;
    }

    for (int a = 0; a < M; ++a)
    {
        cin >> i >> j >> k;

        for (int ii = i; ii <= j; ++ii)
        {
            arr[ii - 1] = k;
        }
    }

    for (int kk = 0; kk < N - 1; ++kk)
    {
        cout << arr[kk] << " ";
    }

    cout << arr[N - 1];

    return 0;
}