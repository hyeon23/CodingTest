#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b){
    // 1. 자주 나오는 단어일수록 앞에 배치
    // 2. 단어의 길이가 길수록 앞에 배치
    // 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
    if(a.second == b.second){
        if(a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    unordered_map<string, int> v;

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        if(str.length() >= m)
            v[str]++;
    }
    vector<pair<string, int>> vec(v.begin(), v.end());
    sort(vec.begin(), vec.end(), compare);
    for(auto p : vec)
        cout << p.first << '\n';
}