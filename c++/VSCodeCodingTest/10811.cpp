#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
//sol1
//     int *arr;
//     int N, M, i, j;
//     cin >> N >> M;
//     arr = new int[N + 1];

//     for (int m = 1; m <= N; m++)
//     {
//         arr[m] = m;
//     }

//     while (M--)
//     {
//         cin >> i >> j;

//         for (int a = 0; a < (j - i + 1) / 2; a++)
//         {
//             int temp = arr[j - a];
//             arr[j - a] = arr[i + a];
//             arr[i + a] = temp;
//         }
//     }

//     for(int i = 1; i <= N; ++i){
//         cout << arr[i] << " ";
//     }
//sol2
//     vector<int> vec;
//     int N, M, i, j;
//     cin >> N >> M;

//     vec.push_back(-1);

//     for (int m = 1; m <= N; m++)
//     {
//         vec.push_back(m);
//     }

//     while (M--)
//     {
//         cin >> i >> j;

//         for (int a = 0; a < (j - i + 1) / 2; a++)
//         {
//             int temp = vec[j - a];
//             vec[j - a] = vec[i + a];
//             vec[i + a] = temp;

//             //swap(vec[j - a], vec[i + a]);
//         }
//     }

//     for(int i = 1; i <= N; ++i){
//         cout << vec[i] << " ";
//     }

    int n, m, i, j;
    cin >> n >> m;
    int* a = new int[n+1];
    for(int i = 1; i <= n; i++)
        a[i] = i;
    while(m--){
        cin >> i >> j;
        for(int t = 0; t <= (j - 1) / 2; ++t){
            swap(a[t+1], a[j-t]);
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << a[i] << ' ';
    }

    return 0;
}