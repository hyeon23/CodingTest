#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    bool arr[5][5] = {false,};

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}