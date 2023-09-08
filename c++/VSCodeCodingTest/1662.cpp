#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    //33(567979)
    //3 567979 567979 567979 => 19
    cin >> S;
    stack<char> stk;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == '('){
            stk.push(S[i]);
        }
        else if(S[i] == ')'){
            
        }
        else{
            stk.push(S[i]);
        }
    }
}