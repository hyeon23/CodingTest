#include <iostream>
using namespace std;

//이항계수(n k)의 정의를 알아야 함
//이항식을 이항정리로 전개했을 때, 각 항의 계수

//이항계수 = nCk = C(n, k)

//반복문 풀이
int factorial(int x){
    int temp = 1;
    for(int i = 1; i <= x; ++i)
        temp *= i;
    return temp;
}

//재귀함수 풀이
int Factorial(int num){
    if(num == 1 || num == 0)
        return 1;
    else
        return Factorial(num - 1) * num;
}

int main(){
    int N, K;
    cin >> N >> K;
    cout << factorial(N) / (factorial(K) * factorial(N - K));
}

