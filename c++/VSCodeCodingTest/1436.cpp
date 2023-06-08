#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    int N;
    int count = 0;
    long long curNum = 666;
    string N_word = "666";
    
    cin >> N;

    while(true){
        string temp = to_string(curNum);

        for(int i = 0; i <= temp.length() - 3; ++i){
            string s = string({ temp[i], temp[i + 1], temp[i + 2] });

            if(N_word == s){
                count++;
                break;
            }
        }

        if(N == count)
            break;
        else
            curNum++;
    }

    cout << curNum;

    return 0;
}