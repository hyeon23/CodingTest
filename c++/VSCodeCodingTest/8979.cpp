#include <bits/stdc++.h>
using namespace std;

struct medal
{
    int na;
    int gold;
    int silver;
    int bronze;
    int rank;
};

bool cmp(medal A, medal B)
{
    if (A.gold == B.gold){
        if (A.silver == B.silver){
            return A.bronze > B.bronze;
        }
        return A.silver > B.silver;
    }
    return A.gold > B.gold;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K, na, go, si, br;
    cin >> N >> K;
    vector<medal> vec(N);
    for (int i = 0; i < N; ++i){
        cin >> na >> go >> si >> br;
        vec.push_back({na, go, si, br, 0});
    }
    sort(vec.begin(), vec.end(), cmp);

    int res = 0;
    for (int i = 0; i < N; i++){
        res = 1;
        for (int j = 0; j < i; j++){
            if ((vec[i].gold == vec[j].gold) 
            && (vec[i].silver == vec[j].silver) 
            && (vec[i].bronze == vec[j].bronze)){
                continue;
            }
            res++;
        }
        vec[i].rank = res;
    }
    for (int i = 0; i < N; i++){
        if (vec[i].na == K){
            cout << vec[i].rank;
            return 0;
        }
    }
    return 0;
}