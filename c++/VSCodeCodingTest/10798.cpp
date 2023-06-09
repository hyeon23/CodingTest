#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//     char arr[5][16] = { 0 };
//     string s;

//     for (int i = 0; i < 5; ++i)
//     {
//         getline(cin, s);

//         for (int j = 0; j < s.length(); ++j)
//         {
//             arr[i][j] = s[j];
//         }
//     }

//     for (size_t i = 0; i < 15; i++)
//     {
//         for (size_t j = 0; j < 5; j++)
//         {
//             if(arr[j][i] != '\0')
//                 cout << arr[j][i];
//         }
//     }
// }

int main(){
    string word[5];
    for(int i = 0 ; i < 5; ++i){
        cin >> word[i];
    }

    for(int i = 0; i < 15; ++i){
        for(int j = 0; j < 5; ++j){
            if(i < word[j].length()){
                cout << word[j][i];
            }
        }
    }
}