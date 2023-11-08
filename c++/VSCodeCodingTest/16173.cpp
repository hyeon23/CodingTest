#include <bits/stdc++.h>
using namespace std;

int N;
int arr[4][4];
bool visited[4][4];
//우, 하 이동
int dx[2] = {0, 1};
int dy[2] = {1, 0};

void dfs(int x, int y){
    stack<pair<int, int>> stk;
    visited[x][y] = true;
    stk.push({x, y});

    while(!stk.empty()){
        pair<int, int> curpos = stk.top();
        stk.pop();
        for(int i = 0; i < N; ++i){
            int nx = curpos.first + dx[i] * arr[curpos.first][curpos.second];
            int ny = curpos.second + dy[i] * arr[curpos.first][curpos.second];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            stk.push({nx, ny});
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while(!q.empty()){
        pair<int, int> curpos = q.front();
        q.pop();
        for(int i = 0; i < N; ++i){
            int nx = curpos.first + dx[i] * arr[curpos.first][curpos.second];
            int ny = curpos.second + dy[i] * arr[curpos.first][curpos.second];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> arr[i][j];
    
    bfs(0, 0);

    if(visited[N-1][N-1]) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}