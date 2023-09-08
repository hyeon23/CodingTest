// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <sstream>
// using namespace std;

// int main(){
//     int N;
    
//     cin >> N;
//     cin.ignore();//cin >> getline 사용시, 입력이 씹히는 현상 방지


//     for(int i = 1; i <= N; ++i){
//         string tmp;
//         getline(cin, tmp);
        
//         string t;

//         vector<string> strvec;

//         stringstream ss(tmp);
        
//         while(ss >> t)
//             strvec.push_back(t);

//         reverse(strvec.begin(), strvec.end());

//         cout << "Case #" << i << ": ";
        
//         for(auto i : strvec)
//             cout << i << ' ';

//         cout << '\n';
//     }
// }

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    stack<string> stk;
    int N;
    cin >> N;
    cin.ignore();

    int i = 1;
    string tmp;
    while(N--){
        getline(cin, tmp);

        stringstream ss(tmp);
        string tmp2;
        while(ss >> tmp2){
            stk.push(tmp2);
        }

        cout << "Case #" << i << ": ";

        while(!stk.empty()){
            cout << stk.top() << ' ';
            stk.pop();
        }
        cout << '\n';

        ++i;
    }
    
}