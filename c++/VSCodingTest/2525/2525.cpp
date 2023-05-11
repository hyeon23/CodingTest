#include <iostream>
using namespace std;

int main() {
	int A, B;
	int C;
	cin >> A >> B;
	cin >> C;

	int afHour = ((A * 60 + B + C) / 60) % 24;
	int afMin = ((A * 60 + B + C) % 60);

	cout << afHour << " " << afMin;
}