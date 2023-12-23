#include <bits/stdc++.h>
using namespace std;
int N;
void cantour(int n){
    //1. base condition 정의
    if(n == 0) {
        cout << '-';
        return;
    }
    //2. f(base condition) -> f(base condition + 1)의 관계에서 규칙(점화식) 찾기
    cantour(n-1);
    for(int i = 0; i < pow(3, (n - 1)); ++i) cout << ' ';
    cantour(n-1);
}
int main(){
    while(cin >> N){
        cantour(N);
        cout << '\n';
    }
    return 0;
}