#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> A, pair<int, int> B){
    if(A.second == B.second){
        return A.first < B.first;
    }
    return A.second > B.second;
}

int main(){
    int N, K, tmp;
    cin >> N >> K;
    vector<pair<int, int>> vec(N);
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        vec[i] = {i, tmp};
    }

    sort(vec.begin(), vec.end(), cmp);

    //1, 3 / 0, 2 / 3, 2 / 2, 1 / 4, 1

    //0, 1, 3

    for(int i = 0; i < K; ++i){
        vec[i].first
    }


    return 0;
}