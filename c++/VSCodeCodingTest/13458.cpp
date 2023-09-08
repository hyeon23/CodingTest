#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, B, C;
    cin >> N;
    vector<int> vec(N);

    for(int i = 0; i < N; ++i)
        cin >> vec[i];
    cin >> B >> C;

    unsigned long long ans = 0;
    for(auto i : vec){
        int tmp = i;
        ans += 1;
        if(tmp >= B)
            ans += ceil((tmp - B) / (double)C);
    }
    cout << ans;
}