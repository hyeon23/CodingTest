#include <iostream>
#include <string>
using namespace std;

int main()
{
    //sol 1
    // cout.tie(NULL);
    // cin.tie(NULL);
    // std::ios_base::sync_with_stdio(false);

    // string s;

    // //한 단어로 이뤄진 경우 펠린드롬을 체크하기 위해 1로 설정
    // int check = 1;

    // cin >> s;

    // for (int i = 0; i < s.length() / 2; ++i)
    // {
    //     if(s[i] != s[s.length() - 1 - i]){
    //         check = 0;
    //         break;
    //     }
    //     else{
    //         if (i == s.length() / 2 - 1)
    //             check = 1;
    //     }
    // }

    // cout << check;

    //sol 2
    string s;
    cin >> s;

    for(int i = 0; i < s.length() / 2; ++i){
        if(s[i] != s[s.length() - i - i]){
            cout << "0" << endl;
            return 0;
        }
    }

    cout << "1" <<endl;
    return 0;
}