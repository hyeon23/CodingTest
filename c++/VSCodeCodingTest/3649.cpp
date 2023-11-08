#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x, n;

    while(cin >> x >> n){
        //1m = 100cm = 10^9 nm
        //1cm = 10^7nm

        x *= 10000000;//나노미터 변환

        //1 센티미터 = 10000000 나노미터

        vector<int> vec(n);
        for(int i = 0; i < n; ++i){
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        int start = 0; int end = n-1;

        bool a = false;

        while(start < end){
            int sum = vec[start] + vec[end];
            if(sum == x){
                a = true;
                break;
            }
            if(sum > x){
                --end;
            }
            else{
                ++start;
            }
        }

        if(!a) cout << "danger" << '\n';
        else{
            cout << "yes " << vec[start] << ' ' << vec[end] << '\n';
        }
    }
    return 0;
}