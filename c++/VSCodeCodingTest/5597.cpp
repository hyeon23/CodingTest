#include <iostream>
#include <algorithm>

using namespace std;

int main(){
//sol1
    int arr[31]{0};
    int isSubmitted;
    
    int arr2[2]{0};


    for(int i = 1; i <= 28; ++i){
        cin >> isSubmitted;

        arr[isSubmitted] = 1;
    }

    int count = 0;

    for(int i = 1; i <= 30; ++i){

        if(arr[i] == 0){
            arr2[count++] = i;
        }
    }

    cout << min(arr2[0], arr2[1]) << endl;
    cout << max(arr2[0], arr2[1]) << endl;
//sol2
    int a;
    bool check[31] = {0,};
    for(int i = 1; i <= 28; ++i){
        cin >> a;
        check[a] = 1;
    }
    for(int j = 1; j <= 30; ++j){
        if(check[j] == 0)
            cout << j << "\n";
    }
    return 0;
}
