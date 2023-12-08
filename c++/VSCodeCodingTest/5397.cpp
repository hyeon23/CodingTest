// #include <iostream>
// #include <string>
// #include <vector>
// #include <stack>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     string str;
//     cin >> T;
//     stack<char> left;
//     stack<char> right;
//     while(T--){
//         cin >> str;
//         //< 커서 왼쪽으로 이동
//         //> 커서 오른쪽으로 이동
//         //- -> 백스페이스
//         //그 외 문자 입력
//         for(int i = 0; i < str.size(); ++i){
//             if(str[i] == '>'){
//                 if(!right.empty()) {
//                     left.push(right.top());
//                     right.pop();
//                 }
//             }
//             else if(str[i] == '<'){
//                 if(!left.empty()) {
//                     right.push(left.top());
//                     left.pop();
//                 }
//             }
//             else if(str[i] == '-'){
//                 if(!left.empty())
//                     left.pop();
//             }
//             else{
//                 left.push(str[i]);
//             }
//         }
//         while(!left.empty()){
//             right.push(left.top());
//             left.pop();
//         }
//         while(!right.empty()){
//             cout << right.top();
//             right.pop();
//         }
//         cout << '\n';
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        list<char> li;
        auto it = li.begin();
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '<'){
                if(it != li.begin()) --it;
            }
            else if(str[i] == '>'){
                if(it != li.end()) ++it;
            }
            else if(str[i] == '-'){
                if (it != li.begin()) {
                    it--;
                    it = li.erase(it);
                }
            }
            else{
                li.insert(it, str[i]);
            }
        }
        for(auto i : li) cout << i;
        cout << '\n';
    }
}