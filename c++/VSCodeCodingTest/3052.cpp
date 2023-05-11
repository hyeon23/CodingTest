#include <iostream>
#include <vector>

using namespace std;

int main(){ 
//sol1
    int arr[42] = { 0,};
    for(int i = 0; i < 10; ++i){
        int x;
        cin >> x;
        arr[x % 42] = 1;
    }

    int count = 0;

    for(int i = 0; i < 42; ++i){
        if(arr[i] == 1)
            ++count;
        cout << arr[i] << endl;
    }

    cout << count;

//sol2
    int arr[42] = {};
    int v;
    for(int i = 0; i < 10; ++i){
        cin >> v;
        arr[v % 42]++;
    }
    int result = 0;

    //범위지정 for문[★★★]
    for(int v : arr){
        if(v > 0){
            result++;
        }
    }
    cout << result;

    return 0;
}