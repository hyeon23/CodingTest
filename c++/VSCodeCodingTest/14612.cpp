#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, n, t, ord;
    cin >> N >> M;
    string cmd;

    vector<pair<int, int>> pvec;
    while(N--){
        cin >> cmd;
        if(cmd == "order"){
            cin >> n >> t;
            pvec.push_back({n, t});
        }
        else if(cmd == "sort"){
            sort(pvec.begin(), pvec.end(), cmp);
        }
        else if(cmd == "complete"){
            cin >> ord;
            for(auto it = pvec.begin(); it != pvec.end(); ++it){
                if(it->first == ord){
                    pvec.erase(it);
                    break;
                }
            }
        }

        if(pvec.size() == 0){
            cout << "sleep" << '\n';
        }
        else{
            for(int i = 0; i < pvec.size(); ++i){
                cout << pvec[i].first << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}