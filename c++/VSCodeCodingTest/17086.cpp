#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int n, m, ans;

vector<vector<int>> board(51, vector<int>(51, 0));
vector<vector<int>> dist(51, vector<int>(51, 0));
vector<vector<bool>> visited(51, vector<bool>(51, false));

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 8; ++i){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            
            if(board[nx][ny] == 1){
                ans = max(ans, dist[nx][ny]);
                return;
            }
            q.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == 1) continue;//사메칸은 안전거리 0

            for(int k = 0; k < 51; ++k){
                fill(visited[k].begin(), visited[k].begin() + 51, 0);
                fill(dist[k].begin(), dist[k].begin() + 51, 0);
            }

            bfs(i, j);
        }
    }
    cout << ans;
}