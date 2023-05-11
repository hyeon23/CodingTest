#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {

	int N;

	int number;
	int min = 1000000;
	int max = -1000000;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number;
		if (number < min) {
			min = number;
		}
		if (number > max) {
			max = number;
		}
	}

	cout << min << " " << max;

	return 0;
}