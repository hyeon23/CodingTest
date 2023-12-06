#include <bits/stdc++.h>
using namespace std;

int next_person[1000];
bool visited[1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int to;
        cin >> to;
        --to;
        next_person[i] = to;
    }

    int meet = 0;
    int min_idx = 0;

    for(int i = 0; i < n; ++i){
        memset(visited, 0, sizeof(visited));

        
    }

    return 0;
}