#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b, a;
    cin >> n >> b >> a;

    vector<int> gifts(n);
    for(int i = 0; i < n; ++i){
        cin >> gifts[i];
    }
    stack<int> stk;
    int cur = 0;
    for(int i = 0; i < n; ++i){
        if(b -= gifts[i] <= 0){
            while(stk.empty())
        }
        else{
            stk.push(gifts[i]);
        }
    }

}