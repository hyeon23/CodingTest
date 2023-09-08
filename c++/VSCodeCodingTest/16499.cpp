#include <bits/stdc++.h>
using namespace std;

//Sol1: 각 문자의 개수만이 중요하기 때문에 이를 map으로 받아들이는 방법
int main(){
    int N;
    string str;
    cin >> N;
    map<map<char, int>, int> m;
    while(N--){
        cin >> str;
        string cpy = str;
        map<char, int> tmp;
        for(int i = 0; i < str.size(); ++i){
            tmp[str[i]]++;
        }
        m[tmp]++;
    }
    cout << m.size();
    return 0;
}

//Sol2: 단어의 순서는 중요하지 않기 때문에 매 순간마다 정렬해서 넣는 방법
#include <bits/stdc++.h>
using namespace std;
int n;
map <string,int> m;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        m[s] = 1;
    }
    cout << m.size();
}