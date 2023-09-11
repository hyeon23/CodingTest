#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<double> vec(N);
    for(int i = 0; i < N; ++i){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    cout << fixed;
    cout.precision(3);

    for(int i = 0; i < 7; ++i){
        cout << vec[i] << '\n';
    }
    return 0;
}