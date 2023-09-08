#include <iostream>

using namespace std;

int factorial(int i){
    if(i == 0)
        return 1;
    else
        return i * factorial(i - 1);
}

int main(){
    int N;
    unsigned long long sum = 1;

    cin >> N;

    for(int i = 1; i <= N; ++i){
        sum *= i;
    }

    cout << sum;
}