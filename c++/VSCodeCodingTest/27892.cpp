// #include <bits/stdc++.h>
// using namespace std;

// #define ulli unsigned long long int

// ulli x0, N;

// ulli XOR(ulli A, ulli B){
//     return (A & !B) | (!A & B);
// }

// ulli NLCS(ulli C, ulli xcur){
//     if(C == N) return xcur % 2 ? XOR(2 * xcur, 6) : XOR(floor(xcur / (float)2), 6);

//     NLCS(C+1, (xcur % 2) == 0 ? XOR(floor(xcur / (float)2), 6) : XOR(2 * xcur, 6));
// }

// int main(){
//     cin >> x0 >> N;

//     cout << NLCS(0, x0);

//     return 0;
// }

#include <iostream>

using namespace std;

unsigned long long calculate_fraction_height(unsigned long long x0, unsigned long long N) {
    for (unsigned long long i = 0; i < N; i++) {
        if (x0 % 2 == 0) {
            x0 = (x0 / 2) ^ 6;  // x0가 짝수인 경우
        } else {
            x0 = (2 * x0) ^ 6;  // x0가 홀수인 경우
        }
    }
    return x0;
}

int main() {
    unsigned long long x0, N;
    cin >> x0 >> N;

    unsigned long long result = calculate_fraction_height(x0, N);

    cout << result << endl;
    
    return 0;
}