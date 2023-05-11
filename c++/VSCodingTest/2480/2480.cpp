#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int arr[3] = { A, B, C };

	if (A == B && B == C) {
		cout << A * 1000 + 10000;
	}
	else if (A != B && B != C && A != C) {
		cout << max(max(A, B), C) * 100;
	}
	else {
		if (A == B) {
			cout << A * 100 + 1000;
		}
		else if (A == C) {
			cout << A * 100 + 1000;
		}
		else {
			cout << B * 100 + 1000;
		}
	}

	return 0;
}