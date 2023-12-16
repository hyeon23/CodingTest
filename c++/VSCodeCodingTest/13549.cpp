// #include <bits/stdc++.h>
// using namespace std;
// int n, k;
// int dist[100001];
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     cin >> n >> k;
//     int MX = 100001;
//     fill(dist, dist + MX, -1);
//     deque<int> dq;
//     dq.push_back(n);
//     dist[n] = 0;
//     while (!dq.empty())
//     {
//         int cur = dq.front();
//         dq.pop_front();
//         if (2 * cur < MX && dist[2 * cur] == -1)
//         {
//             dist[2 * cur] = dist[cur];
//             dq.push_front(2 * cur);
//         }
//         for (int nxt : {cur - 1, cur + 1})
//         {
//             if (nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
//             dist[nxt] = dist[cur] + 1;
//             dq.push_back(nxt);
//         }
//     }
//     cout << dist[k];
// }

#include <bits/stdc++.h>
using namespace std;
int n, k, ans = INT_MAX;
vector<bool> visited(100001, false);
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    deque<pair<int, int>> dq;
    visited[n] = true;
    dq.push_back({n, 0});
    while (!dq.empty())
    {
        int cur = dq.front().first;
        int ccnt = dq.front().second;
        if(cur == k){
            ans = min(ans, ccnt);
        }
        dq.pop_front();
        if (2 * cur < 100001 && !visited[2 * cur])
        {
            visited[2 * cur] = true;
            dq.push_front({2 * cur, ccnt});
        }
        for (int nxt : {cur - 1, cur + 1})
        {
            if (nxt < 0 or nxt >= 100001 or visited[nxt]) continue;
            visited[nxt] = true;
            dq.push_back({nxt, ccnt + 1});
        }
    }
    cout << ans;
}