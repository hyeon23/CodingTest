#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    for(int i = 0; i < n; ++i) cin >> cards[i];

    map<string, int> m;

    while(next_permutation(cards.begin(), cards.end())){
        string str = "";
        for(int j = 0; j < n; ++j){
            str += to_string(cards[j]);
        }
        m[str]++;
    }
    cout << m.size()-1;
    return 0;
}