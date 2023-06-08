#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
//sol1: set으로 줄이고 줄여도 안됨
//vector를 제외한 STL에서 binary_search보다 STL.find()의 기능이 월등히 좋음
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N, M, temp, count = 0;
//     cin >> N >> M;
//     set<int> set1;
//     for(int i = 0; i < N; ++i){
//         cin >> temp;
//         set1.insert(temp);
//     }
//     for(int i = 0; i < M; ++i){
//         cin >> temp;
//         if(set1.find(temp) != set1.end()){
//             ++count;
//         }
//     }
//     cout << N + M - 2 * count;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, temp, count;
    cin >> N >> M;
    map<int, int> map;
    for(int i = 0; i < N; ++i){
        cin >> temp;
        map.insert({temp, 0});
    }
    for(int i = 0; i < M; ++i){
        cin >> temp;
        if(map.find(temp) != map.end()){
            ++count;
        }
    }
    cout << N + M - 2 * count;
}