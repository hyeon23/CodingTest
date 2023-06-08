#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool lengthGreater(string a, string b){
    if(a.length() < b.length()){
        return true;
    }
    else if(a.length() == b.length()){
        return a < b;
    }
    else{
        return false;
    }

    return a.length() < b.length();
}

bool lengthLess(string a, string b){
    if(a.length() > b.length()){
        return true;
    }
    else if(a.length() == b.length()){
        return a > b;
    }
    else{
        return false;
    }

    return a.length() > b.length();
}

int main(){
    int N;
    cin >> N;
    vector<string> vec;

    for(int i = 0; i < N; ++i){
        string s;
        cin >> s;
        vec.push_back(s);
    }

    sort(vec.begin(), vec.end(), lengthGreater);
    
    //중복 제거
    //unique는 중복된 원소를 뒤로 몰아놓고, 이를 구분하는 iter를 반환
    //반환된 iter 기준으로 끝까지 삭제하면 중복되는 원소 제거 끝
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << endl;
    }
}