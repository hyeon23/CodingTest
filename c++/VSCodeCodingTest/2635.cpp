#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second) 
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main(){
    int start;
    cin >> start;

    map<int, int> m;
    map<int, vector<int>> mvec;

    for(int i = 0; i <= start; ++i){
        int newS = start;
        int second = i;

        int cnt = 0;

        vector<int> tmpvec;

        while(second >= 0){
            int tmp = second;

            second = newS - tmp;
            newS = tmp;

            ++cnt;
        }

        m[cnt]++;
        mvec[cnt].push_back(i);
    }

    vector<pair<int, int>> pvec(m.begin(), m.end());

    sort(pvec.begin(), pvec.end(), cmp);

    cout << pvec[0].second << '\n';
    for(auto i : mvec[pvec[0].first]){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}