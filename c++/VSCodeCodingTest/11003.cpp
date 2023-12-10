#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int N, L;
  deque<pair<int, int>> dq;
  cin >> N >> L;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    // 새 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막(back)에 위치하도록 구현
    // deque안 숫자들은 오름차순 상태를 유지하게 됨
    // 구간 내 가장 작은값은 항상 맨앞(front)에 있는 상태가 됨
    while(!dq.empty() && dq.back().second >= num){
        dq.pop_back();
    }
    // 새로운 숫자는 항상 삽입
    dq.push_back({i, num});
    // 주어진 구간을 벗어나는 outdate된 숫자 제거
    if(dq.front().first <= i - L){
        dq.pop_front();
    }
    cout << dq.front().second << ' ';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int x, idx, cur;
  for(int i = 0; i < n; i++) {
    cin >> x;
    pq.push({x, i});
    tie(cur, idx) = pq.top();
    while(idx < max(0, i - m + 1)) {
      pq.pop();
      tie(cur, idx) = pq.top();
    }
    cout << cur << ' ';
  }
}
/*
우선순위 큐를 이용한 풀이
*/