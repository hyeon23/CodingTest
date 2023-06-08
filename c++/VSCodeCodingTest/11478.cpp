#include <set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//sol1: set ver / #include <string> 사용 Ver
int main(){
    string s;
    set<string> set;
    cin >> s;
    set.insert(s);
    for(int i = 1; i <= s.length(); ++i){
        for(int j = 0; j < s.length() - i + 1; ++j)
            set.insert(s.substr(j, i));
    }
    cout << set.size();
}
//sol2: set ver / #include <string> 미사용 Ver
int main() {
    string s;
    cin >> s;
 
    set<string> set;
 
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str);
        }
        str = "";
    }
 
    cout << set.size();
}