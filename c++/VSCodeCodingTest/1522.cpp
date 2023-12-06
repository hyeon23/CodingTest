#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int a = 0;// s내 a의 개수
    int ans = s.size();
    for(auto c : s) if(c == 'a') ++a;
    for(int i = 0; i < s.size(); ++i){
        int cnt = a, temp = 0;
        for(int j = i; j < i + s.size(); ++j){
            if(cnt==0) break;
            if(s[j % s.size()] == 'b') ++temp, --cnt;
            else --cnt;
        }
        ans = min(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}