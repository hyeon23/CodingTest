#include <stdio.h>
#include <string>
#include <iostream>

using std::cin;
using std::cout;

int main() {

	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int T;
	int A, B;

	cin >> T ;

	for (int i = 0; i < T; ++i) {

		cin >> A >> B;
		cout << A + B << '\n';
	}

	return 0;
}