#include <iostream>
#include <regex>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	string str1 = regex_replace("aaa-bba-ccd-daf", regex("a"), "z");
	cout << str1 << '\n';

	return 0;
}