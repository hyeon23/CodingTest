//sol1
/*
임의 자연서 n에 대해, n의 2진수 표현에서 비트 값을 1만큼 바꿔준 수 m을 고려하자.
n의 2진수 표현의 비트 수를 세준 후 2로 나눈 나머지를 출력하면 된다.
*/
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     unsigned long long n;
//     cin >> n;
//     cout << bitset<64>(n-1).count() % 2;
//     return 0;
// }

//sol2
#include <iostream>
using namespace std;
unsigned long long find(unsigned long long x) {
    if (x == 0) return 0;
    else if (x == 1) return 1;
    else if (x % 2 == 0) return find(x / 2);
    else return 1 - find(x / 2);
}
int main() {
    unsigned long long k;
    cin >> k;
    cout << find(k - 1) << '\n';
    return 0;
}