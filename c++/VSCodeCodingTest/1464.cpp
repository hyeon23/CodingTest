#include <bits/stdc++.h>
using namespace std;
set<string> s;

//메모리 초과 재귀 코드
void strbaker(string str, int i){
    if(i == str.size() + 1) return;
    string cpy = str;//BABA
    reverse(cpy.begin(), cpy.begin() + i);
    s.insert(str);
    s.insert(cpy);
    strbaker(str, i + 1);
    strbaker(cpy, i + 1);
}

int main(){
    string tmp;
    cin >> tmp;
    strbaker(tmp, 1);
    //BC BCD DCB
    //CB CBD DBC
    cout << *s.begin() << '\n';
}