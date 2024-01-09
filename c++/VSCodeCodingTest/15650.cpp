// #include <iostream>
// #define MAX 9
// using namespace std;

// int n, m;
// int arr[MAX];//정렬된 순열을 담는 배열
// bool visited[MAX];//이미 방문된 숫자인지 판별하는 bool 배열

// void DFS(int depth, int num)
// {
//     if(depth == m)
//     {
//         for(int i = 0; i < m; i++)
//             cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }
//     for(int i = num; i <= n; i++)
//     {
//         //중복 비허용
//         if(!visited[i])
//         {
//             visited[i] = true;
//             arr[depth] = i;
//             DFS(depth + 1, i + 1);
//             visited[i] = false;
//         }
//     }
// }

// int main() {
//   cin >> n >> m;
//   DFS(0, 1);//깊이 0부터 DFS 시작
// }

#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> vec(9, 0);
vector<bool> visited(9, false);
void DFS(int depth, int num){
    if(depth == M){
        for(int i = 0; i < M; ++i){
            cout << vec[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; ++i){
        if(!visited[i]){
            visited[i] = true;
            vec[depth] = i;
            DFS(depth+1, i+1);
            visited[i] = false;
        }
    }
}
int main(){
    //1 to N 중복 비허용 M개
    //오름차순
    cin >> N >> M;
    DFS(0, 1);
    return 0;
}