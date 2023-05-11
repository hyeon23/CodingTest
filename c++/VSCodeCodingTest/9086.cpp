#include <string>

#include <iostream>

using namespace std;

int main(){
    //sol1
    int T;
    
    string* s;
    
    cin >> T;
    
    s = new string[T];

    for(int i = 0; i < T; ++i){
        
        cin >> s[i];
        cout << s[i][0] << s[i][s[i].length() - 1] << endl;
    }

    //sol2
    int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		cout << str[0] << str[str.length() - 1] << endl;
	}
    return 0;
}