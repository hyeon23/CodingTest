#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length() / 10 + 1; i++) {
		cout << str.substr(i * 10, 10) << endl;
	}

	return 0;
}