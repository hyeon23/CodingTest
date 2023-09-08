#include <bits/stdc++.h>
using namespace std;

//1, 2, 3 .. N
//K번째 사람 제거, 오른쪽 기준 K번 제거...
//제거된 사람의 순서?

int main(){
    int N, K, M;
    cin >> N >> K >> M;
    deque<int> deq;
    for(int i = 1; i <= N; ++i)
        deq.push_back(i);

    int cnt = 0;
    // 1 4 5   

    //k = 3 M = 4
    bool dir = false;//dir = false -> 왼쪽 dir = true -> 오른쪽

    while(!deq.empty()){
        if(cnt % M == 0){//방향 전환
            dir = !dir;
        }

        if(dir){//true = 오른쪽 회전 처리
            for(int i = 0; i < K - 1; ++i){
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else{//false = 왼쪽 회전 처리
            for(int i = 0; i < K; ++i){
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }

        cout << deq.front() << '\n';
        deq.pop_front();
        cnt++;
    }

    
}