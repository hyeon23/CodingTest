#include <bits/stdc++.h>
using namespace std;

//시간초과
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N, M, k, sushi;//N명의 손님, M개의 초밥
//     cin >> N >> M;
//     map<int, priority_queue<int>> orderlist;//손님번호 , 주문목록 집합(순서 상관 X)
//     unordered_map<int, int> eatcnt;//손님번호, 먹은개수
//     //손님: 1 to N; 
    
//     for(int i = 1; i <= N; ++i){
//         cin >> k;
//         while(k--){
//             cin >> sushi;
//             orderlist[i].push(sushi);
//         }
//     }

//     for(int i = 0; i < M; ++i){
//         cin >> sushi;
//         for(int j = 1; j <= N; ++j){
//             //orderlist[j]
//         }
//     }

//     for(int i = 1; i <= N; ++i){
//         if(eatcnt.find(i) != eatcnt.end()) cout << eatcnt[i] << ' ';
//         else cout << 0 << ' ';
//     }
//     return 0;
// }

struct cmp{
    bool operator()(pair<int, int> A, pair<int, int> B){//손님번호, 스시
        if(A.second == B.second)
            return A > B;//이러면 내름차순 적용
        return A.second < B.second;//이러면 오름차순 적용
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, k, sushi;//N명의 손님, M개의 초밥
    cin >> N >> M;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;//손님번호, 원하는 초밥
    priority_queue<int> slist;
    
    for(int i = 1; i <= N; ++i){
        cin >> k;
        while(k--){
            cin >> sushi;
            pq.push({i, sushi});
        }
    }
    for(int i = 0; i < M; ++i){
        cin >> sushi;
        slist.push(sushi);
    }
    map<int, int> m;
    while(!slist.empty()){
        if(slist.top() == pq.top().second){//원하는 초밥이 같다면
            m[pq.top().first]++;
            pq.pop();
            slist.pop();
        }
        else{//원하는 초밥이 다르다면
            if(slist.top() > pq.top().second) slist.pop();
            else if(slist.top() < pq.top().second) pq.pop();
        }
    }
    for(int i = 1; i <= N; ++i){
        cout << m[i] << ' ';
    }
    return 0;
}