#include <stdio.h>
#include <string>
#include <string.h>

#include <iostream>

using namespace std;

int main(){
    //sol1
    //#include <string>
    string s;
    cin >> s;

    cout << s.length() << endl;
    //cout << s.size() << endl;

    //sol2
    //#include <string.h>
    char s2[101];
    cin >> s2;
    cout << strlen(s2) << endl;

    return 0;
}