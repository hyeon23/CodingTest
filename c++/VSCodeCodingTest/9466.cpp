// #include <bits/stdc++.h>
// using namespace std;
// int T, n;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     cin >> T;
//     while(T--){
//         cin >> n;
//         set<int> ans;
//         vector<int> board(n+1, 0);
//         for(int i = 1; i <= n; ++i){
//             cin >> board[i];
//         }
//         for(int i = 1; i <= n; ++i){
//             stack<pair<int, int>> stk;
//             stk.push({i, 0});
//             while(!stk.empty()){
//                 int cx = stk.top().first;
//                 int cc = stk.top().second;
//                 stk.pop();
//                 int nx = board[cx];
//                 if(i == nx){//시작 -> 과정 -> 시작
//                     ans.insert(i);
//                     break;
//                 }
//                 if(nx < 1 || nx > n) continue;
//                 //i == nx가 아닌 경우 -> 잘못된 싸이클 형성
//                 if(cx == nx) break;
//                 if(cc > 1) break;
//                 stk.push({nx, cc+1});
//             }
//         }
//         cout << n - ans.size() << '\n';
//     }
//     return 0;
// }

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;
int t, n;
int graph[MAX];
bool visited[MAX];
bool cycle[MAX];
int cnt;
//3 1 3 7 3 4 6
void hasCycle(int node) {
	visited[node] = true;//1. 방문 노드 방문 체크
	int next = graph[node];//2. 다음 방문 노드 구하기
	if (!visited[next]) {//3. 다음 노드가 방문되지 않은 경우 -> 방문
		hasCycle(next);
	}
	else { //4. 다음 노드가 방문된 경우
        if (!cycle[next]) { //사이클이 아니라면 next까지 포함해서 사이클 완성
		//자기 자신을 포함한 팀의 멤버를 카운트
		    for (int i = next; i != node; i = graph[i]) cnt++; // 팀 멤버 카운트
		    cnt++; //자기 자신 카운트
        }
	}
	cycle[node] = true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) { cin >> n;
		for (int i = 1; i <= n; i++) cin >> graph[i];
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				hasCycle(i);
			}
		}
		cout << n-cnt << '\n';
        //다음 반복 초기화
		cnt = 0;
        fill(visited+1, visited+n+1, false);
        fill(cycle+1, cycle+n+1, false);
	}
	return 0;
}