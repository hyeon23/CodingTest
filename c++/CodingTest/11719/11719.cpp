#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {

	string str;

	while (true) {
		if (getline(cin, str).eof()) {
			break;
		}
		cout << str << endl;
	}



	return 0;
}