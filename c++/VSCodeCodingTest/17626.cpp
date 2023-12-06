#include <bits/stdc++.h>

using namespace std;

int n, number, strike, ball;
vector<bool> arr(1000, true);
string tmp, one, two;
int strike_cnt, ball_cnt, ans;

int main(){
    cin >> n;

    for(int i = 123; i <= 999; ++i)   {
        tmp = to_string(i);

        //한 숫자 안에 같은 숫자가 있는 경우
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
            arr[i] = false;
        
        //한 숫자 안에 0이 들어가 있는 경우
        if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            arr[i] = false;
    }

    for(int i = 1; i <= n; ++i){
        cin >> number >> strike >> ball;

        for(int i = 123; i <= 999; ++i){
            strike_cnt = 0;
            ball_cnt = 0;

            if(arr[i]){
                one = to_string(number);//target
                two = to_string(i);//cur

                for(int x = 0; x < 3; ++x){
                    for(int y = 0; y < 3; ++y){
                        //위치도 같고, 값도 같은 경우
                        if(x == y && one[x] == two[y]) ++strike_cnt;
                        //위치는 다르지만, 값은 같은 경우
                        if(x != y && one[x] == two[y]) ++ball_cnt;
                    }
                }
                //스트라이크나, 볼 cnt 중 하나라도 틀린 경우, 해당 수는 정답 X
                if(strike_cnt != strike || ball_cnt != ball) arr[i] = false;
            }
        }
    }

    for(int i = 123; i <= 999; ++i){
        if(arr[i]) ++ans;
    }
    cout << ans << '\n';
}