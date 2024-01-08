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

//하노이탑 이동횟수 = pow(2,k) - 1;
//이를 활용해 불필요한 재귀 분기를 없앨 수 있지 않을까?

#include <bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
ulli N, K, curK = 0;
void move(ulli from, ulli to){
    ++curK;
    if(curK == K){
        cout << from << ' ' << to << '\n';
        exit(0);
    }
}
void hanoi(ulli N, ulli start, ulli to, ulli bypass){
    if(N == 1){
        move(start, to);
        return;
    }

    int prek = (int)pow(2, N-1)-1;

    if(prek < K) {
        hanoi(N-1, start, bypass, to);
        move(start, to);
    }
    else{
        move(start, to);
        hanoi(N-1, bypass, to, start);
    }
    
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    hanoi(N, 1, 3, 2);
    return 0;
}