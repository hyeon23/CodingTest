#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string yundo, name;
    cin >> yundo >> N;
    vector<pair<int, string>> ans;

    vector<int> str(yundo.size(), 0);

    for(int i = 0; i < yundo.size(); ++i){
        str[i]++;
    }

    for(int i = 0; i < N; ++i){

        cin >> name;

        //확률 계산
        for(int i = 0; i < name.size(); ++i){
            vector<int> str2(yundo.size(), 0);
            for(int j = 0; j < yundo.size(); ++j){
                if(name[i] == yundo[j]){
                    str2[j]++;
                    break;
                }
            }
            
        }

        //횟수, 이름 저장 벡터

    }

    return 0;
}