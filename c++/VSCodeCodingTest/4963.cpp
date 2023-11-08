//#dfs 풀이
// #include <bits/stdc++.h>
// using namespace std;

// //상 하 좌 우 우대상 우대하 좌대상 좌대하
// int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

// int w, h;

// void dfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, pair<int, int> cur){
//     stack<pair<int, int>> stk;

//     visited[cur.first][cur.second] = true;
//     stk.push(cur);

//     while(!stk.empty()){
//         pair<int, int> cur = stk.top();
//         stk.pop();

//         for(int i = 0; i < 8; ++i){
//             int nx = cur.first + dx[i];
//             int ny = cur.second + dy[i];

//             if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

//             if(visited[nx][ny] || arr[nx][ny] == 0) continue;

//             visited[nx][ny] = true;
//             stk.push({nx, ny});
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     while(cin >> w >> h){
//         if(w == 0 || h == 0) break;

//         int cnt = 0;
        
//         vector<vector<int>> arr(h, vector<int>(w));
//         vector<vector<bool>> visited(h, vector<bool>(w));

//         for(int i = 0; i < h; ++i){
//             for(int j = 0; j < w; ++j){
//                 cin >> arr[i][j];
//             }
//         }

//         for(int i = 0; i < h; ++i){
//             for(int j = 0; j < w; ++j){
//                 if(!visited[i][j] && arr[i][j] == 1){
//                     ++cnt;
//                     dfs(arr, visited, {i, j});
//                 }
//             }
//         }

//         cout << cnt << '\n';
//     }
//     return 0;
// }

//#bfs 풀이
#include <bits/stdc++.h>
using namespace std;

//상 하 좌 우 우대상 우대하 좌대상 좌대하
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int w, h;

void bfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, pair<int, int> cur){
    queue<pair<int, int>> que;

    visited[cur.first][cur.second] = true;
    que.push(cur);

    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();

        for(int i = 0; i < 8; ++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

            if(visited[nx][ny] || arr[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(cin >> w >> h){
        if(w == 0 || h == 0) break;

        int cnt = 0;
        
        vector<vector<int>> arr(h, vector<int>(w));
        vector<vector<bool>> visited(h, vector<bool>(w));

        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(!visited[i][j] && arr[i][j] == 1){
                    ++cnt;
                    bfs(arr, visited, {i, j});
                }
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}