// #include <iostream>
// using namespace std;
// int main(){
//     string str;
//     cin >> str;
//     for(int i = 0; i < str.size(); ++i){
//         str[i] = toupper(str[i]);
//     }
//     cout << str;
// }

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    cout << str << '\n';
    return 0;
}