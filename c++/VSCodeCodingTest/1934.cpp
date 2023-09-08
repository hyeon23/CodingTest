#include <iostream>
#include <vector>
using namespace std;

//유클리도 호제법
//최대공약수를 구한 후, 두 수를 각 최대공약수로 나눈 나머지와 최대 공약수를 곱함
int gcd(int x, int y){
    if(x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int main(){
    int T, A, B;
    cin >> T;

    for(int i = 0; i < T; ++i){
        cin >> A >> B;
        if(A >= B)
            cout << A * B / gcd(A, B) << "\n";
        else
            cout << A * B / gcd(B, A) << "\n";
    }
    return 0;
}