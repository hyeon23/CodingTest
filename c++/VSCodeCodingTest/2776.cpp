#include <bits/stdc++.h>
using namespace std;

//시간초과
//map
//통과
//set
//unordered_map
//unordered_set

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, N, M, tmp;
    cin >> T;
    unordered_map<int, int> book;
    while(T--){
        cin >> N;
        book.clear();
        for(int i = 0; i < N; ++i){
            cin >> tmp;
            book[tmp]++;
        }
        cin >> M;
        for(int i = 0; i < M; ++i){
            cin >> tmp;
            if(book[tmp] != 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}