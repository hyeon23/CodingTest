#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, P, L, tmp;
    cin >> n >> m;

    vector<pair<int, vector<int>>> te;

    for(int i = 0; i < n; ++i){
        cin >> P >> L;

        pair<int, vector<int>> p;

        p.first = L;

        for(int i = 0; i < P; ++i){
            cin >> tmp;
            p.second.push_back(tmp);
        }
        sort(p.second.begin(), p.second.end(), greater<int>());
        te.push_back(p);
    }

    

    return 0;
}