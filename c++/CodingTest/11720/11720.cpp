#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	int N;
	string B;
	int sum = 0;

	cin >> N;
	cin >> B;

	for (int i = 0; i < N; i++) {
		sum += B[i] - '0';
	}

	cout << sum << endl;

	return 0;
}