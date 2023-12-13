#include <bits/stdc++.h>
using namespace std;

vector<int> dot(100001, 0);
int N, K;
int dx[2] = {-1, 1};

void bfs(int cur){
    queue<int> q;
    dot[cur] = 1;
    q.push(cur);

    while(!q.empty()){
        int cx = q.front();
        q.pop();

        if(cx == K){
            cout << dot[cx];
            return;
        }

        for(int i = 0; i < 2; ++i){
            int nx = cx + dx[i];

            if(nx < 0 || nx >= 100001) continue;
            if(dot[nx] == 1) continue;
        }
    }
    return;
}

int main(){
    cin >> N >> K;
    bfs(N);
    return 0;
}