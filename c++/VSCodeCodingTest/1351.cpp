#include <bits/stdc++.h>
using namespace std;
long long N, P, Q;
map<long long, long long> m;
long long DP(long long i){
    if(i == 0) return 1;
    //1. 찾았다면 -> 찾은 것 리턴
    if(m.find(i)!=m.end()) return m[i];
    //2. 없다면 -> 찾아서 리턴
    return m[i] = DP(i/P) + DP(i/Q);//정수 나눗셈 = 자동 내림 수행(float)
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> P >> Q;
    cout << DP(N);
}