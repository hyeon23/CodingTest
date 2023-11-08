#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vvec(6, vector<int>(6));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(pair<int, int> cur, int depth, int acnt){

    if(depth == 3 || acnt >= 3) return depth;

    for(int i = 0; i < 4; ++i){
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
        if(vvec[nx][ny] == -1) continue;

        if(vvec[nx][ny] == 1){
            vvec[nx][ny] = -1;
            dfs({nx, ny}, depth+1, acnt+1);
        }
        else if(vvec[nx][ny] == 0) { 
            vvec[nx][ny] = -1;
            dfs({nx, ny}, depth+1, acnt);
        }
    }
}

int main(){
    //5X5 보드 -> 사과(1), 장애물(-1), 빈칸(0)
    //r: 행, c: 열

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cin >> vvec[i][j];
        }
    }

    int r, c;
    
    cin >> r >> c;

    dfs({r, c}, 0, 0);

    return 0;
}