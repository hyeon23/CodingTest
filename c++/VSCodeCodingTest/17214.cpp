#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string s;
    string check;
    int coef = 0;
    int order = 0;
    int stop = 0;
    int k = 0;
    cin >> s;

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'x'){
            order = 1;
            stop = i;
            break;
        }
    }
    if(order == 0){
        coef = stoi(s);
        if(coef == 0)
            cout << "W";
        else if(abs(coef) == 1){
            if(coef == 1)
                cout << "x+W";
            else if(coef == -1)
                cout << "-x+W";
        }
        else
            cout << coef << "x+W";
    }
    else if(order == 1){
        
    }
}