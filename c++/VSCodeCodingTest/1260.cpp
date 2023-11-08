// #include <bits/stdc++.h>
// using namespace std;

// int N, M, V, x, y;
// vector<vector<int>> vvec(1001);
// bool visitedDFS[1001];

// void dfs(int level){
//     for(int i = 1; i <= N; ++i){
//         if(!vvec[i].empty()) sort(vvec[i].rbegin(), vvec[i].rend());
//     }
//     stack<int> stk;
//     stk.push(level);

//     while(!stk.empty()){
//         int cur = stk.top();
//         stk.pop();
//         for(int i = 0; i < vvec[cur].size(); ++i){
//             if(visitedDFS[vvec[cur][i]]) continue;
//             stk.push(vvec[cur][i]);
//         }
//         if(!visitedDFS[cur]) cout << cur << ' ';
//         visitedDFS[cur] = true;
//     }
//     cout << '\n';
// }

// bool visitedBFS[1001];

// void bfs(int level){
//     for(int i = 1; i <= N; ++i){
//         if(!vvec[i].empty()) sort(vvec[i].begin(), vvec[i].end());
//     }
//     queue<int> que;
//     visitedBFS[level] = true;

//     que.push(level);

//     while(!que.empty()){
//         int cur = que.front();
//         que.pop();

//         for(int i = 0; i < vvec[cur].size(); ++i){
//             if(visitedBFS[vvec[cur][i]]) continue;

//             visitedBFS[vvec[cur][i]] = true;
//             que.push(vvec[cur][i]);
//         }
//         cout << cur << ' ';
//     }
//     cout << '\n';
// }

// int main(){
//     cin >> N >> M >> V;

//     for(int i = 0; i < M; ++i){
//         cin >> x >> y;
//         vvec[x].push_back(y);
//         vvec[y].push_back(x);
//     }

//     dfs(V);
//     bfs(V);
//     return 0;
// }

#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
 
int N, M, V; //정점개수, 간선개수, 시작정점
int map[MAX][MAX]; //인접 행렬 그래프
bool visited[MAX]; //정점 방문 여부
queue<int> q;
 
void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}
 
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
            DFS(i);
        }
    }
}
 
void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << " ";
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}
 
int main() {
    cin >> N >> M >> V;
 
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
 
    reset();
    DFS(V);
    
    cout << '\n';
    
    reset();
    BFS(V);
 
    return 0;
}