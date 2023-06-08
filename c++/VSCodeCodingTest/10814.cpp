#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//sol1. mysol: pair와 stable_sort 사용
// bool Pred(pair<int, string> p1, pair<int, string> p2){
//     return p1.first < p2.first;
// }

// int main(){
//     int N;
//     cin >> N;
//     vector<pair<int, string>> vec;
//     for(int i = 0; i < N; ++i){
//         int x; string s;
//         cin >> x >> s;
//         vec.push_back({x, s});
//     }

//     stable_sort(vec.begin(), vec.end(), Pred);

//     for(auto i : vec){
//         cout << i.first << " " << i.second << '\n';
//     }
// }

//sol2. mysol: triple struct제작과 sort 사용
struct person{
    int age, idx;
    string name;
};

bool compare(const person& now, const person& last){
    if(now.age != last.age) return now.age < last.age;
    return now.idx < last.idx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    person people[100001];//구조체 배열

    for(int i = 0; i < N; ++i){
        cin >> people[i].age >> people[i].name;
        people[i].idx = i;
    }

    //정렬
    sort(people, people + N, compare);

    for(int i = 0; i < N; ++i)
        cout << people[i].age << " " << people[i].name << "\n";
}