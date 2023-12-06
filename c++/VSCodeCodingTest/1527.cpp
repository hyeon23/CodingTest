// #include <bits/stdc++.h>
// using namespace std;
// char num[8] = {'0', '1', '2', '3', '5', '8', '9'};

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int A, B;
//     cin >> A >> B;

//     int cnt = 0;
//     bool flag = true;
//     for(int i = A; i <= B; ++i){
//         flag = true;
//         string N = to_string(i);
//         for(int j = 0; j < 8; ++j){
//             if(N.find(num[j]) != -1){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag) ++cnt;
//     }
//     cout << cnt << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int A, B;

// int dfs(int s, int cnt, int ans){
//     if(cnt >= 10) return 0;
//     if(s > B) return 0;
//     if(s >= A) ++ans;
//     int ansTmp = ans;
//     ans += dfs(s*10 + 4, cnt+1, ans);
//     ans += dfs(s*10 + 7, cnt+1, ansTmp);
//     return ans;
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     cin >> A >> B;
//     cout << dfs(0, 0, 0) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int A, B;
int ans;

void dfs(int s, int cnt){
    if(cnt >= 10) return;
    if(s > B) return;
    if(s >= A) ++ans;
    dfs(s*10 + 4, cnt+1);
    dfs(s*10 + 7, cnt+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> A >> B;
    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}