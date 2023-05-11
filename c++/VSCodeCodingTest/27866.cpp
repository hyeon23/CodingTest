#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    //sol1
    // string S;
    // unsigned int i;
    // cin >> S >> i;

    // cout << S[i-1];

    //sol2
    char s[1001];
    int i;

    scanf("%s %d", &s, &i);
    printf("%c", s[i - 1]);

    return 0;
}