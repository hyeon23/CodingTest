// #include <bits/stdc++.h>
// using namespace std;

// 시간초과: O(n2)코드
// int main(){
//     int n, h, o, d;
//     cin >> n;

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq2;

//     for(int i = 0; i < n; ++i){
//         cin >> h >> o;
//         pq.push({min(h, o), max(h, o)});
//         pq2.push({max(h, o), min(h, o)});
//     }

//     int ans = 0;
//     cin >> d;
//     for(int i = pq.top().first; i <= pq2.top().first; ++i){
//         int tmp = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> cpy = pq;

//         while(!cpy.empty()){
//             if(i <= cpy.top().first && i + d >= cpy.top().second){
//                 tmp++;
//             }
//             cpy.pop();
//         }
//         ans = max(ans, tmp);
//     }
//     cout << ans;
// }

#include <bits/stdc++.h>
using namespace std;

int N, L, h, o;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> h >> o;
        if(h > 0) swap(h, o);
        v.push_back({h, o});
    }
    cin >> L;

    //끝 점을 기준으로 오름차순 정렬, 끝점의 위치가 같을 경우, 시작점의 위치가 낮은게 앞으로 가도록 
    sort(v.begin(), v.end(), cmp);

    int result = 0;

    for(int i = 0; i < v.size(); ++i){
        int start = v[i].first;
        int end = v[i].second;

        //A to B 거리가 철로의 길이보다 긴 경우 -> 패스
        if(end - start > L) continue;

        pq.push(start);

        while(!pq.empty()){
            //(A, A + 철로의 길이) 범위 안에 End가 존재할 경우
            if(pq.top() + L >= end){
                result = max(result, (int)pq.size());
                break;
            }
            //(A, A + 철로의 길이) 범위 밖에 End가 존재할 경우
            else{
                pq.pop();
            }
        }
    }

    cout << result << '\n';

    return 0;
}