#include <bits/stdc++.h>
using namespace std;

int n, m, k, p, ti, qi;
vector<long long> t, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    t.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> k;
        for(int j = 0; j < k; ++j){
            cin >> ti;
            t[i] |= (1ll << ti);
        }
    }
}