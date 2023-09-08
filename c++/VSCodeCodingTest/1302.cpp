#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> m;
    int N, max_val;
    cin >> N;
    string s;
    while(N--){
        cin >> s;
        m[s]++;
    }
    for(auto p : m) max_val = max(max_val, p.second);
    for(auto p : m){
        if(p.second == max_val){
            cout << p.first;
            return 0;
        }
    }
}