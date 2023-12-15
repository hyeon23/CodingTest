#include <bits/stdc++.h>
using namespace std;
int T, n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        set<int> ans;
        vector<int> board(n+1, 0);
        for(int i = 1; i <= n; ++i){
            cin >> board[i];
        }
        for(int i = 1; i <= n; ++i){
            stack<pair<int, int>> stk;
            stk.push({i, 0});
            while(!stk.empty()){
                int cx = stk.top().first;
                int cc = stk.top().second;
                stk.pop();
                int nx = board[cx];
                if(i == nx){//시작 -> 과정 -> 시작
                    ans.insert(i);
                    break;
                }
                if(nx < 1 || nx > n) continue;
                //i == nx가 아닌 경우 -> 잘못된 싸이클 형성
                if(cx == nx) break;
                if(cc > 1) break;
                stk.push({nx, cc+1});
            }
        }
        cout << n - ans.size() << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int n;
int state[100001]; 
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;
void run(int x){
  int cur = x;
  while(true){
    state[cur] = x;
    cur = arr[cur];
    // 이번 방문에서 지나간 학생에 도달했을 경우
    if(state[cur] == x){
      while(state[cur] != CYCLE_IN){
        state[cur] = CYCLE_IN;
        cur = arr[cur];
      }
      return;
    }
    // 이전 방문에서 지나간 학생에 도달했을 경우
    else if(state[cur] != 0) return;
  }
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    fill(state+1, state+n+1, 0);
    for(int i = 1; i <= n; i++)
      cin >> arr[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
      if(state[i] == NOT_VISITED) run(i);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      if(state[i] != CYCLE_IN) cnt++;
    }
    cout << cnt << '\n';
  }
}