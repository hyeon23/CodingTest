#include <bits/stdc++.h>
using namespace std;

int answer(int A, int B){
    return powl(A, 2) - powl(B, 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long A, B;
    cin >> A >> B;
    cout << (A + B) * (A - B);
}