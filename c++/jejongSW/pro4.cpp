#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vvecDFS(1001);
vector<bool> isvisitedDFS(1001);

void dfs(int cur){
    //현재 점 방문 체크
    if(isvisitedDFS[cur]) return;

    //방문 체크
    isvisitedDFS[cur] = true;

    //현재 점부터 재귀 방문

    cout << cur << ' ';

    for(int i = 0; i < vvecDFS[cur].size(); ++i){
        dfs(vvecDFS[cur][i]);
    }
}

vector<vector<int>> vvecBFS(1001);
vector<bool> isvisitedBFS(1001);

void bfs(int cur){
    queue<int> q;

    q.push(cur);

    while(!q.empty()){
        int cn = q.front();
        if(isvisitedBFS[cn]) return;

        isvisitedBFS[cur] = true;
        q.pop();

        cout << cn << ' ';

        for(int i = 0; i < vvecBFS[cn].size(); ++i){
            q.push(vvecBFS[cn][i]);
        }
    }
}

//DFS = 재귀 or 스택
//BFS = 큐

//DFS 스택 구현 = BFS 큐 구현(구현 방법이 유사)
int main(){
    int N, M, V, x, y;

    cin >> N >> M >> V;

    for(int i = 0; i < M; ++i){
        cin >> x >> y;
        vvecDFS[x].push_back(y);
        vvecDFS[y].push_back(x);

        vvecBFS[x].push_back(y);
        vvecBFS[y].push_back(x);
    }

    for(int i = 0; i < N; ++i){
        sort(vvecDFS[i].begin(), vvecDFS[i].end());
    }

    dfs(V);
    cout << '\n';
    bfs(V);
}