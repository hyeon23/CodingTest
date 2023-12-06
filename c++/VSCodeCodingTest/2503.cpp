#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, number, strike, ball;
    string tmp, one, two;
    int strike_cnt, ball_cnt, ans;

    vector<bool> arr(1000, true);
    
    cin >> n;

    for(int i=123; i<=999; ++i){
        tmp = to_string(i);

        //한 숫자안에 같은 숫자가 있으면 false
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) arr[i] = false;

        //한 숫자 안에 '0'이 있으면 false
        if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') arr[i] = false;
    }

    for(int i = 1; i <= n; ++i){
        cin >> number >> strike >> ball;

        strike_cnt = 0;
        ball_cnt = 0;

        if(arr[i]){
            one = to_string(number);
            two = to_string(i);

            for(int x = 0; x < 3; ++x){
                for(int y = 0; y < 3; ++y){
                    if(x == y && one[x] == two[y]) ++strike_cnt;
                    if(x != y && one[x] == two[y]) ++ball_cnt;
                }
            }
            if(strike_cnt != strike || ball_cnt != ball) arr[i] = false;
        }
    }

    for(int i = 123; i <= 999; ++i)
        if(arr[i]) ++ans;

    cout << ans << '\n';

    return 0;
}