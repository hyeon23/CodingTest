#include <bits/stdc++.h>
using namespace std;
int N, M, ans = INT_MAX;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<char>> board(1001, vector<char>(1001, '1'));
bool visited[1001][1001] = {false,};

struct DATA{
    int x;
    int y;
    int dist;
    bool b;
};

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> board[i][j];
        }
    }
    bool trigger = false;
    queue<DATA> que;
    visited[0][0] = true;
    que.push({0, 0, 1, true});
    while(!que.empty()){
        DATA cur = que.front();
        if(cur.x == N-1 && cur.y == M-1){
            ans = min(ans, cur.dist);
            trigger = true;
        }
        que.pop();
        for(int i = 0; i < 4; ++i){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] == '1'){//현재 벽을 만난 경우
                if(cur.b){//현재 벽을 부술 수 있다면
                    //벽을 부숨
                    visited[nx][ny] = true;
                    que.push({nx, ny, cur.dist+1, false});
                }
                else{//벽을 부술 수 없다면
                    continue;
                }
            }
            else if(board[nx][ny] == '0'){//그 외 -> 일반 BFS처럼 수행
                visited[nx][ny] = true;
                que.push({nx, ny, cur.dist+1, cur.b});
            }
        }
    }
    if(trigger) cout << ans;
    else cout << -1;
    return 0;
}