//[◎]
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str = "";
    cin >> str;

    int num = 0, ptr = 0;

    while(num++ < 30000){
        string numstr = to_string(num);
        for(int i = 0; i < numstr.size(); ++i){
            if(str[ptr] == numstr[i]) ++ptr;
            if(ptr == str.size()){
                cout << num;
                return 0;
            }
        }
    }
}