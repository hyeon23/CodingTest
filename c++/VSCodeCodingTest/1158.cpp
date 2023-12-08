#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for(int i = 1; i <= N; ++i){
        q.push(i);
    }
    cout << '<';
    while(!q.empty()){
        for(int i = 0; i < K - 1; ++i){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();

        if(q.size()) cout << ", ";
    }
   cout << '>'; 
}

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int N, K;
//     cin >> N >> K;
//     list<int> q;
//     for(int i = 1; i <= N; ++i){
//         q.push_front(i);
//     }
//     long long cnt = 0;
//     cout << '<';
//     while(!q.empty()){
//         ++cnt;
//         if(cnt % K == 0){
//             if(q.size() == 1) cout << q.back();
//             else cout << q.back() << ", ";
//             q.pop_back();
//         }
//         else{
//             q.push_front(q.back());
//             q.pop_back();
//         }
//     }
//    cout << '>'; 
// }