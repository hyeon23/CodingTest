#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int K, N, len;
    cin >> K >> N;

    vector<int> lens(K);

    for(int i = 0; i < K; ++i){
        cin >> lens[i];
    }

    sort(lens.begin(), lens.end());

    int sum = accumulate(lens.begin(), lens.end(), 0) / N;




    return 0;
}