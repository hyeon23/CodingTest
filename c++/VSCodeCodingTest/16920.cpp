#include <bits/stdc++.h>
using namespace std;
int N, M, P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int diax[4] = {1, 1, -1, -1};
int diay[4] = {1, -1, 1, -1};
int board[1001][1001];
vector<int> player_dist(10, 0);
vector<int> castle_cnt(10, 0);
queue<tuple<int, int, int>> que;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
void bfs(){
    while(!que.empty()){
        auto cur = que.front();
        int cp = get<0>(cur);
        int cx = get<1>(cur);
        int cy = get<2>(cur);
        castle_cnt[cp]++;
        que.pop();
        for(int dist = 1; dist <= player_dist[cp]; ++dist){
            for(int i = -dist; i <= dist; ++i){
                for(int j = dist; j >= -dist; --j){
                    if(abs(i) + abs(j) == dist){
                        int nx = cx + i;
                        int ny = cy + j;
                        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                        if(board[nx][ny] != 0) continue;
                        board[nx][ny] = cp;
                        que.push({cp, nx, ny});
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> P;
    char tmp;
    for(int i = 1; i <= P; ++i) cin >> player_dist[i];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> tmp;
            if(tmp == '.') board[i][j] = 0;
            else if(tmp == '#') board[i][j] = -1;
            else { 
                board[i][j] = tmp - '0';
                pq.push({tmp - '0', i, j});
            }
        }
    }
    while(!pq.empty()){
        que.push(pq.top());
        pq.pop();
    }
    bfs();
    for(int i = 1; i <= P; ++i){
        cout << castle_cnt[i] << ' ';
    } 
    return 0;
}