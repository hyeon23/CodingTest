#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
vector<int> v;

void dfs(int num, int ten){
    if(num > N) return;

    ans = max(ans, num);

    for(int i = 0; i < v.size(); ++i)
        dfs(num + ten * v[i], ten * 10);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;

    int input;

    for(int i = 0; i < K; ++i){
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end()); // 1, 5, 7

    dfs(0, 1);

    cout << ans << '\n';
}