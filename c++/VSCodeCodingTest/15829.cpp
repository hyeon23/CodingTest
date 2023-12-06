#include <bits/stdc++.h>
using namespace std;
//tmp

int main(){
    //해시함수 -> 자료의 저장과 탐색에 쓰임
    int L, r, k;
    cin >> L;

    string str;
    cin >> str;

    long long sum = 0;
    long long int a;
    for(long long i = 0; i < L; ++i){
        long long ai = (str[i] - 'a' + 1);

        long long ri = 1;

        for(int j = 0; j < i; ++j){
            ri = ((ri % 1234567891) * 31) % 1234567891;
        }
        
        sum += ((ai % 1234567891) * (ri % 1234567891)) % 1234567891;
    }

    cout << sum % 1234567891;

    return 0;
}