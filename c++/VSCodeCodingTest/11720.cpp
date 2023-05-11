#include <iostream>
#include <string>
using namespace std;

int main()
{
//char로 하면 -'\0' or 48을 빼줌

    //sol1
    int N;
    string s;

    cin >> N >> s;

    int sum = 0;

    for(int i = 0; i < N; ++i){
        sum += (int)(s[i] - 48);
    }

    cout << sum;

    // sol2
    // int N;

    // char s[101];

    // cin >> N >> s;

    // int sum = 0;

    // for (int i = 0; i < N; ++i)
    // {
    //     sum += s[i] - '0';
    // }

    // cout << sum;

    return 0;
}