// #include <bits/stdc++.h>
// using namespace std;
// int N, M, K, ans = INT_MAX;
// //4방향 이동 or 머무르기 가능(낮 visited 배열 or 밤 visited 배열)
// int dx[5] = {0, 1, 0, -1, 0};
// int dy[5] = {0, 0, 1, 0, -1};
// vector<vector<char>> board(1001, vector<char>(1001, '1'));
// vector<vector<vector<bool>>> visited_day(1001, vector<vector<bool>>(1001, vector<bool>(11, false)));
// vector<vector<vector<bool>>> visited_night(1001, vector<vector<bool>>(1001, vector<bool>(11, false)));
// struct DATA{
//     int x;
//     int y;
//     int k;
//     int cnt;
//     int day ;
// };
// //낮 시작 / 이동 시, 낮 / 밤이 바뀜
// void bfs(int x, int y){
//     int daynight = 0;
//     queue<DATA> que;
//     visited_day[x][y][0] = true;
//     que.push({x, y, 0, 0, 0});
//     while(!que.empty()){
//         DATA cur = que.front();
//         que.pop();
//         if(cur.x == N-1 && cur.y == M-1){
//             ans = min(ans, cur.cnt);
//             return;
//         }
//         for(int i = 0; i < 5; ++i){
//             int nx = cur.x + dx[i];
//             int ny = cur.y + dy[i];
//             if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
//             //낮 or 밤
//             if(cur.day == 0){//낮
//                 if(i == 0){//제자리 moving
//                     if(visited_night[nx][ny][cur.k]) continue;
//                     visited_night[nx][ny][cur.k] = true;
//                     que.push({nx, ny, cur.k, cur.cnt+1, (cur.day + 1) % 2});
//                 }
//                 else{
//                     if(board[nx][ny] == '1'){//벽이라면
//                         if(cur.k >= K) continue;
//                         if(visited_night[nx][ny][cur.k+1]) continue;
//                         visited_night[nx][ny][cur.k+1] = true;
//                         que.push({nx, ny, cur.k+1, cur.cnt+1, (cur.day + 1) % 2});
//                     }
//                     else if(board[nx][ny] == '0'){
//                         if(visited_night[nx][ny][cur.k]) continue;
//                         visited_night[nx][ny][cur.k] = true;
//                         que.push({nx, ny, cur.k, cur.cnt+1, (cur.day + 1) % 2});
//                     }
//                 }

//             }
//             else if(cur.day == 1){//밤
//                 if(i == 0){//제자리 moving
//                     if(visited_day[nx][ny][cur.k]) continue;
//                     visited_day[nx][ny][cur.k] = true;
//                     que.push({nx, ny, cur.k, cur.cnt+1, (cur.day + 1) % 2});
//                 }
//                 else{
//                     if(visited_day[nx][ny][cur.k] || board[nx][ny] == '1') continue;
//                     visited_day[nx][ny][cur.k] = true;
//                     que.push({nx, ny, cur.k, cur.cnt+1, (cur.day + 1) % 2});
//                 }
//             }
//         }
//         daynight = (daynight + 1) % 2;
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     cin >> N >> M >> K;
//     for(int i = 0; i < N; ++i){
//         for(int j = 0; j < M; ++j){
//             cin >> board[i][j];
//         }
//     }
//     bfs(0, 0);
//     if(ans == INT_MAX) cout << -1;
//     else cout << ans+1;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1001];
// x, y, 부순 횟수, 낮/밤 여부(낮 = 0, 밤 = 1)
int dist[1001][1001][11][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void input_opti()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool bfs(){
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    dist[0][0][0][0] = 1;
    while (!q.empty())
    {
        auto [x, y, w, t] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
            cout << dist[x][y][w][t] << '\n';
            return true;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // 만약 (nx, ny)가 빈 곳이라면 편하게 가면 된다.
            if (board[nx][ny] == '0')
            {
                int nw = w;
                int nt = 1 - t;
                if (dist[nx][ny][nw][nt] > 0)
                    continue;
                dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
                q.push({nx, ny, nw, nt});
            }
            // 비어있지 않다면
            else
            {
                // 이미 k번 깼으면 더 깰 수 없다.
                if (w == k)
                    continue;
                // 낮이라면 깨고 넘어가면 된다.
                if (t == 0)
                {
                    int nw = w + 1;
                    int nt = 1 - t;
                    if (dist[nx][ny][nw][nt] > 0)
                        continue;
                    dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
                    q.push({nx, ny, nw, nt});
                }
                // 밤이라면 낮이 올 때 까지 기다려야 한다.
                // 다음 좌표가 (nx, ny, nw, nt)가 아닌 (x, y, w, nt)라는 점에 주의한다.
                else
                {
                    int nt = 1 - t;
                    if (dist[x][y][w][nt] > 0)
                        continue;
                    dist[x][y][w][nt] = dist[x][y][w][t] + 1;
                    q.push({x, y, w, nt});
                }
            }
        }
    }
    return false;
}
int main(void)
{
    //입력 최적화
    input_opti();
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> board[i];
    if(!bfs()) cout << -1;
}