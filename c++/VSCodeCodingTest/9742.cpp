// #include<bits/stdc++.h>
// using namespace std;
// int N;
// string str;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     while(cin >> str >> N){
//         int cnt = 0;
//         bool trigger = false;
//         string tmp = str;
//         while(cnt < N-1){
//             ++cnt;
//             if(!next_permutation(str.begin(), str.end())){
//                 trigger = true;
//                 break;
//             }
//         }
//         if(trigger) cout << tmp << ' ' << N << " = " << "No permutation" << '\n';
//         else cout << tmp << ' ' << N << " = " << str << '\n';
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int N, cnt = 0;
string str;
bool tri = false;
vector<char> vec(11);
vector<bool> visited(11);
void DFS(int depth){
    if(depth == str.size()){
        ++cnt;
        if(cnt == N){
            string tmp = "";
            for(int i = 0; i < str.size(); ++i){
                tmp += vec[i];
            }
            if(tmp > str) {
                tri = true;
                cout << str << ' ' << N << " = " << tmp << '\n';
            }
        }
        return;
    }
    for(int i = 0; i < str.size(); ++i){
        if(visited[i]) continue;
        visited[i] = true;
        vec[depth] = str[i];
        DFS(depth+1);
        visited[i] = false;
    }
}
int main(){
    while(cin >> str >> N){
        cnt = 0;
        tri = false;
        vec.clear();
        visited.clear();
        DFS(0);
        if(!tri) cout << str << ' ' << N << " = " << "No permutation" << '\n';
    }
    return 0;
}