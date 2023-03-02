#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			cout << " ";
		}

		cout << "*";

		for (int k = 0; k < 2 * i; k++) {
			if (i == N - 1) {
				cout << "*";
			}
			else {
				if (k == 2 * i - 1) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}