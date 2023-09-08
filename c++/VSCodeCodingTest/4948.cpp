#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, rt, cnt = 0;

    while (1){
        cin >> n;
        if(!n) break;

        for(int i = n + 1; i <= 2 * n; ++i){
            rt = sqrt(i);
            if(rt == 1 && i != 1){//2, 3 case
                cnt++;
                continue;
            }
            if(i % 2){//3 초과의 홀수일 경우
                for(int j = 2; j <= rt; ++j){
                    if(!(i%j))//나눠지는 수가 존재할 경우
                        break;
                    if(j == rt)//나눠지는 수가 sqrt(x)까지 존재하지 않는 경우 소수라 판별
                        cnt++;
                }
            }
        }
        cout << cnt << '\n';
        cnt = 0;
    }
}