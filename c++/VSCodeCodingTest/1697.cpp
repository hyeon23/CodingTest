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
        int nx;
        //+1이동
        nx = cx + 1;
        if(nx < 0 || nx >= 100001) continue;
        if(dot[nx] == 1) continue;
        dot[nx] = 1;

        //-1이동
        nx = cx - 1;
        if(nx < 0 || nx >= 100001) continue;
        if(dot[nx] == 1) continue;
        dot[nx] = 1;

        //순간이동
        nx = cx * 2;
        if(nx < 0 || nx >= 100001) continue;
        if(dot[nx] == 1) continue;
        dot[nx] = 1;
        
        if(nx < 0 || nx >= 100001) continue;
        if(dot[nx] == 1) continue;
        dot[nx] = 1;
        
    }
    return;
}

int main(){
    cin >> N >> K;
    bfs(N);
    return 0;
}