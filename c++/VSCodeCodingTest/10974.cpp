// #include <bits/stdc++.h>
// using namespace std;

// int N;
// int num[9];
// int visited[9];

// void permutation(int idx){
//     if(idx == N){
//         for(int i=0; i<N; ++i)
//             cout << num[i] << ' ';
//         cout << '\n';
//         return;
//     }

//     for(int i=0; i<N; ++i){
//         if(!visited[i]){
//             visited[i] = true;
//             num[idx] = i+1;
//             permutation(idx+1);
//             visited[i] = false;
//         }
//     }
// }

// int main(){
//     cin >> N;
//     permutation(0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> vec(9);
vector<bool> visited(9);
void DFS(int depth){
    if(depth == N){
        for(int i = 0; i < N; ++i){
            cout << vec[i] << ' ';
        }
        cout << '\n';
    }
    for(int i = 1; i <= N; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        vec[depth] = i;
        DFS(depth+1);
        visited[i] = false;
    }
}
int main(){
    cin >> N;
    DFS(0);
    return 0;
}