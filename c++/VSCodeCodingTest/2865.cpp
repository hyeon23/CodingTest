#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, float> p1, pair<int, float> p2){
    return p1.second > p2.second;
}

int main(){
    int N, M, K, num;
    float gang;

    map<int, float> stats;

    cin >> N >> M >> K;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cin >> num >> gang;
            stats[num] += gang;
        }
    }

    vector<pair<int, float>> stats2(stats.begin(), stats.end());

    sort(stats2.begin(), stats2.end(), cmp);

    cout << fixed;
    cout.precision(1);
    cout << round(stats2[0].second);
    return 0;
}