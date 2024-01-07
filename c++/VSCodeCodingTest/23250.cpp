//sol1: 시간초과: 정직하게 k번 옮기면 안됨
// #include <bits/stdc++.h>
// #define ulli unsigned long long int
// using namespace std;
// ulli N, K, curK = 0;
// void move(ulli from, ulli to){
//     ++curK;
//     if(curK == K){
//         cout << from << ' ' << to << '\n';
//         exit(0);
//     }
// }
// void hanoi(ulli N, ulli start, ulli to, ulli bypass){
//     if(N == 1){
//         move(start, to);
//         return;
//     }
//     hanoi(N-1, start, bypass, to);
//     move(start, to);
//     hanoi(N-1, bypass, to, start);
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     cin >> N >> K;
//     hanoi(N, 1, 3, 2);
//     return 0;
// }

#include <iostream>
#define ulli unsigned long long int
using namespace std;

ulli l[1];

void hanoi(ulli n, ulli a, ulli c, ulli b) {
    if (n == 0) {
        return;
    }
    if (l[0] - (1 << (n - 1)) + 1 <= 0) {
        hanoi(n - 1, a, b, c);
    } else {
        l[0] = l[0] - (1 << (n - 1)) + 1;
    }
    l[0] -= 1;
    if (l[0] == 0) {
        cout << a << " " << c << endl;
        exit(0);
    }
    if (l[0] - (1 << (n - 1)) + 1 <= 0) {
        hanoi(n - 1, b, c, a);
    } else {
        l[0] = l[0] - (1 << (n - 1)) + 1;
    }
}
int main() {
    ulli n, k;
    cin >> n >> k;
    l[0] = k;
    hanoi(n, 1, 3, 2);
    return 0;
}