#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque<int> sche;
    int N, Q, k, cmd, tmp;
    cin >> N >> Q >> k;

    for(int i = 0; i < Q; ++i){
        cin >> cmd;

        if(cmd == 0){
            cin >> tmp;
            sche.push_back(tmp);
        }
        else if(cmd == 1){
            sort(sche.begin(), sche.end(), greater<int>());
        }
        else if(cmd == 2){
            reverse(sche.begin(), sche.end());
        }
    }

    while(k-- > 1){
        sche.pop_back();
    }
    cout << sche.back();
}