#include <bits/stdc++.h>
using namespace std;
string str;
vector<bool> visited(101, false);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> str;
    int len = str.length();
    for(int i = 0; i < len; ++i){
        vector<pair<string, int>> vec;//각 case를 저장할 vector
        for(int j = 0; j < len; ++j){
            //사용된적 없는 문자라면
            if(!visited[j]){
                string temp;
                //이전에 사용한 문자들 추가
                for(int k = 0; k < len; ++k){
                    if(k == j || visited[k]){
                        temp += str[k];
                    }
                }
                vec.push_back({temp, j});
            }
        }
        sort(vec.begin(), vec.end());
        cout << vec[0].first << '\n';
        visited[vec[0].second] = true;
    }
}