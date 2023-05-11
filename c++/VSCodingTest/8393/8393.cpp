#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {

	//sol 1
	int N;

	int sum = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		sum += i;
	}

	cout << sum;

	//sol 2

	/*int n;

	cin >> n;

	cout << n * (n + 1) / 2;*/

	return 0;
}