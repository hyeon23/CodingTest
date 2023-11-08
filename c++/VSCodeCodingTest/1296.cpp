#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main(){
    int L, O, V, E, N;

    string yun;

    cin >> yun;

    for(int i = 0; i < yun.size(); ++i){
        if(yun[i] == 'L'){
            L++;
        }
        else if(yun[i] == 'O'){
            O++;
        }
        else if(yun[i] == 'V'){
            V++;
        }
        else if(yun[i] == 'E'){
            E++;
        }
    }

    cin >> N;

    vector<pair<string, int>> pvec;

    for(int i = 0; i < N; ++i){
        int Lcnt = L;
        int Ocnt = O;
        int Vcnt = V;
        int Ecnt = E;

        string curName;
        cin >> curName;

        for(int j = 0; j < curName.size(); ++j){
            if(curName[i] == 'L'){
                Lcnt++;
            }
            else if(curName[i] == 'O'){
                Ocnt++;
            }
            else if(curName[i] == 'V'){
                Vcnt++;
            }
            else if(curName[i] == 'E'){
                Ecnt++;
            }
        }
        pvec.push_back({curName, (((Lcnt + Ocnt) % 100) * ((Lcnt + Vcnt) % 100) * ((Lcnt + Ecnt) % 100) * ((Ocnt + Vcnt) % 100) * ((Ocnt + Ecnt) % 100) * ((Vcnt + Ecnt) % 100)) % 100});
    }

    sort(pvec.begin(), pvec.end(), cmp);

    cout << pvec[0].first;
}