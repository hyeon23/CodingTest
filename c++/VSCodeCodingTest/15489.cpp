#include <bits/stdc++.h>
using namespace std;

int main(){
    int R, C, W;
    //R번째 줄, C번째 수를 꼭짓점으로 하는 한 변이 포함하는 수의 개수가 W인 정삼각형의 
    //모든 수의 합을 구해라

    cin >> R >> C >> W;

    //0C0
    //1C0 1C1
    //2C0 2C1 2C2 
    //3C0 3C1 3C2 3C3

    //R층 to R + W층
    //1개, 2개, ... W개

    int ans = 0;

    for(int i = 0; i < W; ++i){
        for(int j = 0; j <= i; ++j){
            
        }   
    }


    return 0;
}