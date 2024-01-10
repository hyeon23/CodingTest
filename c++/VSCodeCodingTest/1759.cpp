#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int L, C;
vector<char> v;
string curstr;
bool check(){
    int moum = 0;
    for(int i = 0; i < L; ++i){
        if(curstr[i] == 'a' ||
        curstr[i] == 'e' ||
        curstr[i] == 'i' ||
        curstr[i] == 'o' ||
        curstr[i] == 'u') 
        moum++;
    }
    //모음 수 1개 이상, 자음 수 = 전체 수 - 모음 수 = 2개 이상
    if(moum >= 1 && L - moum >= 2) 
        return true;
    else
        return false;
}
void DFS(int N){
    if((int)curstr.size() == L){
        if(check()){
            for(int i = 0; i < L; ++i){
                cout << curstr[i];
            }
            cout << '\n';
        }
        return;        
    }
    for(int i = N; i < C; ++i){
        curstr.push_back(v[i]);//들어갈 때, 추가
        DFS(i + 1);
        curstr.pop_back();//나올 때, 빼기
    }
}   
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> L >> C;
    for(int i = 0; i < C; ++i){
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    DFS(0);
}