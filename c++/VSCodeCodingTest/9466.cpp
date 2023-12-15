#include <bits/stdc++.h>
using namespace std;
int T, n;
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> ans;
        vector<int> board(n+1, 0);
        vector<bool> visited(n+1, false);
        for(int i = 1; i <= n; ++i){
            cin >> board[i];
        }
        for(int i = 1; i <= n; ++i){
            stack<int> stk;
            visited[i] = true;
            stk.push(i);
            while(!stk.empty()){
                int cx = stk.top();
                stk.pop();
                int nx = board[cx];
                if(cx < 1 || cx > n || visited[nx]) continue;
                if(i == nx){//시작 -> 과정 -> 시작
                    ans.push_back(i);
                    break;
                }
                if(cx == nx){//i == nx가 아닌 경우 -> 잘못된 싸이클 형성
                    
                }
            }
        }
    }
    return 0;
}