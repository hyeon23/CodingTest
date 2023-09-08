#include <bits/stdc++.h>
using namespace std;
//시간초과 코드
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    long long tmp;
    cin >> N;
    vector<long long> arr1(N);
    for(int i = 0; i < N; ++i)
        cin >> arr1[i];

    cin >> M;

    for(int i = 0; i < M; ++i){
        cin >> tmp;
        if(find(arr1.begin(), arr1.end(), tmp) != arr1.end()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N, M;
//     long long tmp;
//     cin >> N;
//     set<int> s;
//     for(int i = 0; i < N; ++i){
//         cin >> tmp;
//         s.insert(tmp);
//     }
//     cin >> M;

//     for(int i = 0; i < M; ++i){
//         cin >> tmp;
//         if(s.count(tmp) != 0) cout << 1 << '\n';
//         else cout << 0 << '\n';
//     }
// }