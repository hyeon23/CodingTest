#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// template<typename _Ty>
// struct greater{
//     bool operator()(const _Ty& _left, const _Ty _right) const{
//         return (_left > _right);
//     }
// };

// template<typename _Ty>
// struct less{
//     bool operator()(const _Ty& _left, const _Ty _right) const{
//         return (_left < _right);
//     }
// };

int main(){
    string N;
    vector<char> vec;
    cin >> N;

    for(int i = 0; i < N.length(); ++i){
        vec.push_back(N[i]);

    }

    sort(vec.begin(), vec.end(), greater<char>());

    for(auto i : vec){
        cout << i;
    }

    return 0;
}