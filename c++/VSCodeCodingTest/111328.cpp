#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        string input, output;
        cin >> input >> output;
        vector<int> alpha(26, 0);

        for(auto c : input) alpha[c - 'a']++;
        for(auto c : output) alpha[c - 'a']--;

        bool trigger = true;
        
        for(int i : alpha){
            if(i != 0) trigger = false;
        }
        if(!trigger) cout << "Impossible" << '\n';
        else cout << "Possible" << '\n';
    }
    return 0;
}
