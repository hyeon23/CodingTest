#include <bits/stdc++.h>
using namespace std;

bool sume(string A, string B){
    unordered_map<char, char> um;
    unordered_map<char, bool> valid; //알파벳이 사용되었는지 확인
    for(int i = 0; i < A.size(); ++i){
        if(!um[A[i]] && !valid[B[i]]){
            um[A[i]] = B[i];
            valid[B[i]] = true;
        }
        else{
            if(um[A[i]] != B[i]) return false;
        }
    }
    return true;
}

int main(){
    //A를 숌스럽게 B로 바꾸면 => A와 B는 비슷한 단어

    //A에 등장하는 모든 알파벳을 다른 알파벳으로 바꾼다는 소리
    
    //A에 등장하는 모든 알파벳을 다른 알파벳으로 바꾼다.

    int n, answer = 0;
    cin >> n;

    vector<string> svec(n);

    for(int i = 0; i < n; ++i)
        cin >> svec[i];

    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){

            //if(현재 선택 쌍 (i, j)가 숌스럽게 비슷한 단어인지 체크)
                //answer++;

            if(sume(svec[i], svec[j]))
                ++answer;
        }
    }

    cout << answer;

    return 0;
}