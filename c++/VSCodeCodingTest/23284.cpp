#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> stk;

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;

            if(stk.empty()){
                stk.push(i);
            }
            else{
                if(stk.top() <= j){

                }
                else{

                }
            }
        }
    }
}