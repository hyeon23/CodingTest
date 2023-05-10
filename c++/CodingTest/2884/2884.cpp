#include <iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	int altotalMin = 60 * H + M - 45;

	if (altotalMin < 0) {
		altotalMin = 24 * 60 + altotalMin;

		cout << altotalMin / 60 << " " << altotalMin % 60;
	}
	else if (altotalMin == 0) {
		cout << "0 0";
	}
	else {
		cout << altotalMin / 60 << " " << altotalMin % 60;
	}
}