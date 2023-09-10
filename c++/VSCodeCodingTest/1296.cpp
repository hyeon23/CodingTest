#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> A, pair<string, int> B){
    if(A.second == B.second){
        return A.first < B.first;
    }
    return A.second > B.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    string mj, str;
    cin >> mj;

    vector<int> mjcnt(mj.size(), 0);
    //mj의 L, O, V, E 숫자 카운팅

    for(int i = 0; i < mj.size(); ++i){
        if(mj[i] == 'L'){
            mjcnt[0]++;
        }
        else if(mj[i] == 'O'){
            mjcnt[1]++;
        }
        else if(mj[i] == 'V'){
            mjcnt[2]++;
        }
        else if(mj[i] == 'E'){
            mjcnt[3]++;
        }
    }


    cin >> N;
    vector<pair<string, long long>> ans(N);

    for(int i = 0; i < N; ++i){
        cin >> str;//세는 단어
        vector<int> strcnt(str.size(), 0);

        for(int j = 0; j < str.size(); ++j){
            if(str[j] == 'L'){
                strcnt[0]++;
            }
            else if(str[j] == 'O'){
                strcnt[1]++;
            }
            else if(str[j] == 'V'){
                strcnt[2]++;
            }
            else if(str[j] == 'E'){
                strcnt[3]++;
            }
        }

        vector<int> tmp(4, 0);

        for(int j = 0; j < 4; ++j){
            tmp[j] = (mjcnt[j] + strcnt[j]);
        }

        long long sum = 1;

        for(int j = 0; j < 4; ++j){
            for(int k = j + 1; k < 4; ++k){
                sum *= (tmp[j] + tmp[k]);
            }
        }

        ans[i] = {str, sum % 100};
    }

    sort(ans.begin(), ans.end(), cmp);

    cout << ans[0].first;
}