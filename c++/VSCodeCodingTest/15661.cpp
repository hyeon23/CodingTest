#include <bits/stdc++.h>
using namespace std;

int main(){
    //start / link
    //무조건 둘둘이 차이가 적다? -> 아닐수도
    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> board[i][j];

    

    return 0;
}