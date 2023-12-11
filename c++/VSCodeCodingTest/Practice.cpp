// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int ans = 0;
//     string str;
//     cin >> str;
//     stack<char> stk;
//     for(int i = 0; i < str.size(); ++i){
//         if(str[i] == '(') stk.push(str[i]);
//         else if(str[i] == ')'){
//             stk.pop();
//             //막대의 끝일 경우
//             if(str[i-1] == ')') ++ans;
//             //레이저일 경우
//             else ans += stk.size();
//         }
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    string str;
    stack<char> stk;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '('){
            stk.push(str[i]);
        }
        else{
            stk.pop();
            if(str[i-1] == '(') ans += stk.size();
            else ++ans;
        }
    }
    cout << ans;
    return 0;
}