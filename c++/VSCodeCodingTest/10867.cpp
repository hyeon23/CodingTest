#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, tmp;
    cin >> N;
    set<int> s;
    while(N--){
        cin >> tmp;
        s.insert(tmp);
    }

    for(auto i : s){
        cout << i << ' ';
    }
    return 0;
}