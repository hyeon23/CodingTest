#include <bits/stdc++.h>
using namespace std;

int main(){
    int L;
    cin >> L;
    vector<int> vec(L);
    for(int i = 0; i < L; ++i){
        cin >> vec[i];
    }
    
    int n;
    cin >> n;

    sort(vec.begin(), vec.end());

    bool t = false;

    int ans;

    for(int i = 0; i < vec.size(); ++i){
        if(n > vec[i]){
            ans = - vec[i];
            t = true;
        }

        if(n < vec[i]){
            t = false;
            ans = ans + vec[i];
            break;
        }
    }

    cout << ans - 2;
}