#include <bits/stdc++.h>
using namespace std;

int main(){
    //단순 큐 풀이로 인한 시간 초과: 슬라이딩 윈도우로 풀어야 함
    int N, K;
    string str;
    cin >> N >> K;

    //일단 친구여야 함 = 등수 차이가 K보다 작거나 같아야 함
    //좋은 친구여야 함 = 이름의 길이(nl)가 같아야 함

    deque<pair<int, int>> sts;//등수, 길이
    stack<pair<int, int>> stk;
    int rfcnt = 0;

    // 1 3

    // 2 3

    for(int i = 0; i < N; ++i){
        cin >> str;
        sts.push_back({i, str.size()});
    }

    while(!sts.empty()){
        pair<int, int> f = sts.back();
        sts.pop_back();

        if(sts.empty()) break;

        for(int i = 0; i < K; ++i){
            if(sts.empty()) break;

            if(sts.back().second == f.second){
                rfcnt++;
                stk.push(sts.back());
                sts.pop_back();
            }
        }

        while(!stk.empty()){
            sts.push_back(stk.top());
            stk.pop();
        }
    }
    cout << rfcnt;
}