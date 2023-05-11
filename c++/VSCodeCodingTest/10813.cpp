#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
//sol1
    // int *arr;
    // int N, M;
    // cin >> N >> M;

    // arr= new int[N];

    // int i, j, k;

    // for (int jj = 0; jj < N; ++jj)
    // {
    //     arr[jj] = jj + 1;
    // }

    // for (int a = 0; a < M; ++a)
    // {
    //     cin >> i >> j;
    //     int temp = arr[i-1];
    //     arr[i-1] = arr[j-1];
    //     arr[j-1] = temp;
    // }

    // for (int kk = 0; kk < N - 1; ++kk)
    // {
    //     cout << arr[kk] << " ";
    // }

    // cout << arr[N - 1];

//sol2
    // vector<int> vec;
    // int N, M;
    // cin >> N >> M;

    // int i, j, k;

    // for (int jj = 0; jj < N; ++jj)
    // {
    //     vec.push_back(jj + 1);
    // }

    // for (int a = 0; a < M; ++a)
    // {
    //     cin >> i >> j;
    //     int temp = vec[i-1];
    //     vec[i-1] = vec[j-1];
    //     vec[j-1] = temp;
    // }

    // for (int kk = 0; kk < N - 1; ++kk)
    // {
    //     cout << vec[kk] << " ";
    // }

    // cout << vec[N - 1];

//sol3
    int n, m, a, b;
    cin >> n >> m;
    int* bas = new int[n+1];
    for(int i = 1; i <= n; ++i){
        bas[i] = i;
    }
            
    while(m--){
        cin >> a >> b;
        swap(bas[a], bas[b]);
    }
    for(int i = 1; i <= n; ++i){
        cout << bas[i] << ' ';
    }
    return 0;
}