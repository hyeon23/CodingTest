#include <bits/stdc++.h>
using namespace std;
int N, K;
int dx[2] = {1, -1};
int main(){
    cin >> N >> K;
    deque<pair<int, int>> deq;
    vector<bool> visited(100001, false);
    deq.push_back({N, 0});
    while(!deq.empty()){
        pair<int, int> cur = deq.front();
        if(cur.first == K){
            cout << cur.second;
            break;
        }
        deq.pop_front();
        
        int nx = 2 * cur.first;
        if(nx < 0 || nx >= 100001 || visited[nx]) continue;
        visited[nx] = true;
        deq.push_back({nx, cur.second});

        for(int i = 0; i < 2; ++i){
            nx = cur.first + dx[i];
            if(nx < 0 || nx >= 100001 || visited[nx]) continue;
            visited[nx] = true;
            deq.push_back({nx, cur.second+1});
        }
    }
    return 0;
}