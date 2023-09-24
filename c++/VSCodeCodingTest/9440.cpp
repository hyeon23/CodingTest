#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    while(true){
        cin >> N;
        if(N == 0) break;

        vector<int> vec(N);

        for(int i = 0; i < N; ++i){
            cin >> vec[i];
        }

        sort(vec.begin(), vec.end());

        string num1 = "";
        string num2 = "";

        int idx = 0;

        stack<int> zstk;

        while(idx != vec.size()){
            if(vec[idx] == 0){
                zstk.push(0);
            }
            else{
                if(idx % 2 == 0){
                    num1 += to_string(vec[idx]);
                }
                else{
                    num2 += to_string(vec[idx]);
                }
            }
            idx++;
        }

        while(!zstk.empty()){
            if(num1.size() == num2.size()){
                num1.insert(1, "0");
            }
            else if(num1.size() > num2.size()){
                num2.insert(1, "0");
            }
            zstk.pop();
        }

        //10 9 8 7 6 5 0 1 2 3 4

        //0 1 2 3 4 5 6 7 8 9 10

        cout << stoi(num1) + stoi(num2) << '\n';
    }
    return 0;
}