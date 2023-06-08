#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    //병신같이 map 1개로 지랄해서 정렬함수 만들어서 풀다가 map 2개 쓰니까 정답
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    string s;
    map<int, string> map1;
    map<string, int> map2;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> s;
        map1[i] = s;
        map2[s] = i;
    }
    for(int i = 0; i < M; ++i){
        cin >> s;
        if(s[0] > '9')//alphabet
            cout << map2[s] << '\n';
        else//numeric
            cout << map1[stoi(s)] << '\n';
    }

    return 0;
}