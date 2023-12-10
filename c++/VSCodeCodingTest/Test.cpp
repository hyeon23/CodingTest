// #include <bits/stdc++.h>
// using namespace std;
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int N, L;
//     cin >> N >> L;
//     int x, idx, cur;
//     for(int i = 0; i < N; ++i){
//         cin >> x;
//         pq.push({x, i});
//         cur = pq.top().first;
//         idx = pq.top().second;
//         while(idx < max(0, i - L + 1)){
//             pq.pop();
//             cur = pq.top().first;
//             idx = pq.top().second;
//         }
//         cout << cur << ' ';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
deque<pair<int, int>> deq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, L, num;
    cin >> N >> L;
    for(int i = 0; i < N; ++i){
        cin >> num;
        while(!deq.empty() && deq.back().second >= num) deq.pop_back();
        deq.push_back({i, num});
        if(deq.front().first <= i - L) deq.pop_front();
        cout << deq.front().second << ' ';
    }
    return 0;
}