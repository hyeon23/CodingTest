#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //바구니 야바위

    //MySol
    // int N, M, i, j, k;

    // cin >> N >> M;

    // vector<int> buskets;
    // vector<int> busketsTEMP;

    // for (int a = 0; a < N + 1; ++a)
    // {
    //     buskets.push_back(a);
    //     busketsTEMP.push_back(-1);
    // }

    // for (int a = 0; a < M; ++a)
    // {
    //     cin >> i >> j >> k;

    //     for (int b = 1; b < N + 1; ++b)
    //     {
    //         busketsTEMP[b] = buskets[b];
    //     }

    //     for (int c = i; c <= j; ++c)
    //     {
    //         buskets[c] = busketsTEMP[i + (k + c - 2 * i) % (j - i + 1)];
    //     }
    // }

    // for(int d = 1; d < N + 1; ++d){
    //     cout << buskets[d] << " ";
    // }

    //sol2: #include <algorithm> rotate()를 이용한 간단 구현
    int n, m; cin >> n >> m; vector<int> v;

    for(int i = 1; i <= n; ++i){
        v.push_back(i);
    }

    while(m--){
        int i, j, k; cin >> i >> j >> k;

        //범위 (i - 1) ~ (j - 1)
        //시작 값은 k번째 값으로 변경 & rotateion
        //왼쪽으로
        rotate(v.begin() + (i-1), v.begin() + (k-1), v.end() + j);
    }

    for(int a : v)
        cout << a << " ";

    cout << "\n";

    return 0;
}