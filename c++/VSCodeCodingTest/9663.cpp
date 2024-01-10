// #include <iostream>
// #define MAX 15
// using namespace std;

// int col[MAX];
// int N, total = 0;

// bool check(int level){
//     for(int i = 0; i < level; ++i)
//         if(col[i] == col[level] || abs(col[level] - col[i]) == level - i){
//             //대각선 or 같은라인
//             //col[i] = x좌표, i = y좌표 -> 차이가 일정하다면, 대각선에 있음
//             return false;
//         }
//     return true;
// }

// void N_Queen(int x){//N_Queen = 퀸 배치
//     if(x == N)
//         total++;
//     else{
//         for(int i = 0; i < N; ++i){
//             col[x] = i;
//             if(check(x))//유효하다면 다음 퀸 배치
//                 N_Queen(x + 1);
//         }
//     }
// }

// void N_Queen(int x){
//     if(x == N) ++total;
//     else{
//         for(int i = 0; i < N; ++i){
//             col[x] = i;
//             if(check(x)) N_Queen(x+1);
//         }
//     }
// }

// int main(){
//     cin >> N;
//     N_Queen(0);
//     cout << total;
// }

#include <bits/stdc++.h>
using namespace std;
int N, ans = 0;
vector<bool> visited(16, false);
vector<int> board(16, -1);
bool check(int row, int col){
    for(int i = 0; i < row; ++i){
        //row: 현재 퀸을 놓을 x위치
        //col: 현재 퀸을 놓을 y위치
        //i : 
        //1. 가로 배치 체크는 자동으로 수행
        //2. 세로 배치 체크
        //3. 대각선 배치 체크
        if(board[i] == col || abs(row - i) == abs(col - board[i])){
            return false;
        }
    }
    return true;
}
void N_Queen(int row){
    if(row == N){//모든 체스말 선택 완료
        ++ans;
        return;
    }
    for(int col = 0; col < N; ++col){
        if(check(row, col)){
            board[row] = col;
            N_Queen(row+1);
            board[row] = -1;
        }
    }
}

int main(){
    cin >> N;
    N_Queen(0);
    cout << ans;
    return 0;
}