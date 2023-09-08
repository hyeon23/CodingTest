#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int N;
    long long cursor = 0;
    string num;
    cin >> num >> N;
    string dict = "0123456789abcdef";
    
    for(int i = 0; i < N; ++i){
        string type;
        string curnum;
        cin >> type;

        if(type == "int"){
            curnum = num.substr(cursor, 8);
            cursor += 8;
        }
        else if(type == "char"){
            curnum = num.substr(cursor, 2);
            cursor += 2;
        }
        else if(type == "long_long"){
            curnum = num.substr(cursor, 16);
            cursor += 16;
        }
        
        long long sum = 0;
        for(int j = curnum.size() - 1; j >= 0; --j){
            sum += dict.find(curnum[j]) * pow(16, curnum.size() - 1 - j);
        }
        cout << sum << ' ';
    }
}