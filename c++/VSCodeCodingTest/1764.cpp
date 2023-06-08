#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//sol1: set
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    string temp;
    cin >> N >> M;
    set<string> set1;
    set<string> set2;
    vector<string> vec;
    for(int i = 0; i < N; ++i){
        cin >> temp;
        set1.insert(temp);
    }
    for(int i = 0; i < M; ++i){
        cin >> temp;
        set2.insert(temp);
    }
    for(auto i : set1){
        if(set2.find(i) != set2.end()){
            vec.push_back(i);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for(auto i : vec){
        cout << i << '\n';
    }
}

//sol2: map
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> map;
    vector<string> vec;
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N + M; ++i){
        string s;
        cin >> s;
        map[s]++;
        if(map[s] > 1)
            vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for(auto i : vec){
        cout << i << '\n';
    }
}


//sol3: 이분탐색
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> vec1;
    vector<string> vec2;
    
    int N, M;
    string s;
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i){
        cin >> s;
        vec1.push_back(s);
    }
    sort(vec1.begin(), vec1.end());
    for(int i = 0; i < M; ++i){
        cin >> s;
        if(binary_search(vec1.begin(), vec1.end(), s)){
            vec2.push_back(s);
        }
    }
    sort(vec2.begin(), vec2.end());
    cout << vec2.size() << '\n';
    for(auto i : vec2){
        cout << i << '\n';
    }
}