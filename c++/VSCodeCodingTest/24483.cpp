#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> vvec(100001);
vector<bool> visited(100001);
vector<pair<long long, long long>> ans(100001, {-1, 0});
long long depth = 0;
long long rnk = 1;

void dfs(long long cur){
    if(visited[cur]) return;

    visited[cur] = true;
    ans[cur].first = depth;
    ans[cur].second = rnk;

    depth++;
    rnk++;

    for(int i = 0; i < vvec[cur].size(); ++i){
        dfs(vvec[cur][i]);
    }

    depth--;
}


int main(){
    long long N, M, R, u, v;
    cin >> N >> M >> R;

    for(long long i = 1; i <= M; ++i){
        cin >> u >> v;
        vvec[u].push_back(v);
        vvec[v].push_back(u);
    }

    for(long long i = 1; i <= N; ++i){
        sort(vvec[i].begin(), vvec[i].end());
    }

    dfs(R);

    long long sum = 0;

    for(long long i = 1; i <= N; ++i){
        sum += ans[i].first * ans[i].second;
    }

    cout << sum;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int N, M, R, u, v;
// vector<bool> visited(100001);
// int depth = 0;

// void dfs(vector<vector<int>>& vec, vector<int>& ans, int point){
//     //방문 체크
//     if(visited[point]) return;
    
//     //현재 점 방문
//     visited[point] = true;

//     ans[point] = depth;

//     depth++;

//     sort(vec[point].begin(), vec[point].end());

//     for(int i = 0; i < vec[point].size(); ++i){
//         dfs(vec, ans, vec[point][i]);
//     }

//     depth--;
// }