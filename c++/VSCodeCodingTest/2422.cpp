#include <bits/stdc++.h>
using namespace std;

int dict[201][201];

int main(){
    int N, M, ans=0;
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int x, y;
        cin >> x >> y;
        dict[x][y] = dict[y][x] = true;
    }

    for(int i = 1; i <= N; ++i){
        for(int j = i+1; j <= N; ++j){
            if(dict[i][j] || dict[j][i]) continue;
            for(int k = j+1; k <= N; ++k){
                if(dict[i][k] || dict[j][k]) continue;
                ++ans;
            }
        }
    }
    cout << ans;
}