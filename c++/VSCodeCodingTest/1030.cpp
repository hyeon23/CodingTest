#include <bits/stdc++.h>
using namespace std;
int s, N, K, R1, R2, C1, C2;
int main(){
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    
    for(int i = C1; i <= C2; ++i){
        for(int j = R1; j <= R2; ++j){
            //조건 수정
            if(i / 3 == 1 && j / 3 == 1){
                cout << '1';
            }
            else{
                //재귀 발생
                cout << '0';
            }
        }
        cout << '\n';
    }

    return 0;
}