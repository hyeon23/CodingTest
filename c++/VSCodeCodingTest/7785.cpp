#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //sol1: multimap을 이용한 나의 풀이법
    // int N;
    // string s1, s2;
    // cin >> N;
    // multimap<string, string> map;
    // for(int i = 0; i < N; ++i){
    //     cin >> s1 >> s2;
    //     if(s2 == "enter")
    //         map.insert({s1, s2});
    //     else if(s2 == "leave")
    //         map.erase(s1); //map.find(s1)
    // }

    // for(auto iter = map.rbegin(); iter != map.rend(); ++iter){
    //     cout << (*iter).first << '\n';
    // }

    //sol2: set만을 이용한 우수한 풀이법
    int N;
    cin >> N;
    set<string> set;
    for(int i = 0; i < N; ++i){
        string s1, s2;
        cin >> s1 >> s2;

        if(s2 == "enter")
            set.insert(s1);
        else
            set.erase(s1);
    }

    for(auto iter = set.rbegin(); iter != set.rend(); ++iter){
        cout << *iter << "\n";
    }

}