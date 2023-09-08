//sol1
#include <iostream>
using namespace std;

void solve(){
    int k, int n;
    cin >> k >> n;

    int DP[15][15];

    for(int i = 0; i < 15; ++i)    {
        DP[0][i] = i;
    }

    for(int i = 1; i <= k; ++i)
        for(int j = 1; j <= n; ++j)
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];

    cout << DP[k][n] << '\n';
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

//sol2
#include <iostream>

using namespace std;

int getNum(int a, int b){
    if(b == 1)
        return 1;
    if(a == 0)
        return b;
    return getNum(a - 1, b) + getNum(a, b-1);
}

int main(){
    int T, k, n;
    cin >> T;
    for(int i = 0; i < T; ++i){
        cin >> k >> n;
        cout << getNum(k, n) << '\n';
    }
}