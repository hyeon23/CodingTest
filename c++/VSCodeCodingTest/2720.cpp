#include <iostream>
using namespace std;

int main(){
    int T;
    int C;

    int coins[4] = {25, 10, 5, 1};

    cin >> T;
    int arr[T][4] = {};

    for(int i = 0; i < T; ++i){
        cin >> C;//센트

        for(int j = 0; j < 4; ++j){
            if(j != 3){
                if(C >= coins[j]){
                    arr[i][j] = C / coins[j];
                    C = C % coins[j];
                }
            }
            else{
                arr[i][j] = C;
            }
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int T,paymoney;

    cin >> T;

    while(T--) {
        int Q=0,D=0,N=0,P=0;
        cin >> paymoney;
        while(paymoney) {
            if(paymoney>=25) {
                Q++;
                paymoney-=25;
            } else if(paymoney>=10) {
                D++;
                paymoney-=10;
            } else if(paymoney>=5) {
                N++;
                paymoney-=5;
            } else {
                P++;
                paymoney-=1;
            }
        }
        cout << Q <<" "<< D <<" "<< N <<" "<< P << "\n";
    }
}