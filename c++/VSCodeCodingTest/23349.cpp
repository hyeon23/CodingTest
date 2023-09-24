#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        
    }
    return p1.second < p2.second;
}

int main(){
    int N, start, end;
    cin >> N;

    string name, place;

    set<string> namel;
    map<string, vector<pair<int, int>>> mvec;

    for(int i = 0; i < N; ++i){
        cin >> name >> place >> start >> end;
        if(namel.find(name) != namel.end()) continue;

        namel.insert(name);

        mvec[place].push_back({start, end});
    }

    for(auto it = mvec.begin(); it != mvec.end(); ++it){
        vector<pair<int, int>>& cur = it->second;
        sort(cur.begin(), cur.end(), cmp);
    }



    return 0;
}