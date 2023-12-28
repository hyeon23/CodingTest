//파티션을 재귀(DFS)를 사용해서 구현하되, 문자열을 더해가며 구한다.
//체크되는 순간 => 팰린드롬 체크

#include <bits/stdc++.h>
using namespace std;
int T, num, cnt;
bool isPalindrome(string str){
    int strlen = str.size();
    for(int i = 0; i < strlen / 2; ++i)
        if(str[i] != str[strlen - 1 - i]) 
            return false;
    return true;
}
void recursion(int cur, string curstr){
    if(cur > num) return;
    if(cur == num){
        if(isPalindrome(curstr)){
            cout << curstr << '\n';
            ++cnt;
        }
        return;
    }
    for(int i = 1; i < num; ++i){
        recursion(cur + i, curstr + to_string(i));
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> num;
        recursion(0, "");
        cout << cnt << '\n';
    }
    return 0;
}