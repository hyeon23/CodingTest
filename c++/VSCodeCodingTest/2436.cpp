#include <bits/stdc++.h>
using namespace std;

int gcd, lcm;
int A = 0, B = 0;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main(){
    cin >> gcd >> lcm;
    int divide = lcm / gcd;

    for(int i = 1; i <= sqrt(divide); ++i){
        //나눠 떨어질 경우 -> 약수를 찾음
        if(divide % i == 0){
            int a = i, b = divide / i;

            if(GCD(a, b) == 1){//서로소 체크
                A = a;
                B = b;
            }
        }
    }
    cout << A * gcd << ' ' << B * gcd;
}