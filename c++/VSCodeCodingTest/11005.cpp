#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N, B;
    vector<char> vec;
    cin >> N >> B;
    string dic = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int tempVal = N;

    while(true){
        if(tempVal / B < B){
            if(tempVal % B == 0 && tempVal / B == 0){

            }
            else if(tempVal / B == 0){
                vec.push_back(dic[tempVal % B]);
            }
            else{
                vec.push_back(dic[tempVal % B]);
                vec.push_back(dic[tempVal / B]);
            }
            break;
        }
        else{
            vec.push_back(dic[tempVal % B]);    
            
            tempVal = tempVal / B;
        }

    }

    for(int i = vec.size() - 1; i >= 0 ; --i){
        cout << vec[i];
    }

    return 0;
}

