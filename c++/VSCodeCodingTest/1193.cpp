#include <iostream>
using namespace std;

int main(){
    // int X;

    // cin >> X;
    // int i = 1;
    // while(X > i){
    //     X -= i;
    //     i++;
    // }

    // if(i % 2 == 0){//짝
    //     cout << X << "/" << i - X + 1;
    // }
    // else{//홀
    //     cout << i - X + 1 << "/" << X;
    // }

    int X;

    cin >> X;
    int count = 1;
    while(true){
        if(X - count > 0){
            X -= count;
            count++;
        }
        else{
            break;
        }
    }

    if(count % 2 == 0){//짝
        cout << X << "/" << count - X + 1;
    }
    else{//홀
        cout << count - X + 1 << "/" << X;
    }

    return 0;
}