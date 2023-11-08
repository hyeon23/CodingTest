#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int H, Y;
    cin >> H >> Y;
    
    int dp[16] = {0,};
    dp[5] = H;
    for(int i = 6; i <= 15; ++i){
        dp[i] = max(max(dp[i-1] * 1.05, dp[i-3] * 1.2), dp[i-5] * 1.35);
    }
    cout << dp[Y+5];
    return 0;
}