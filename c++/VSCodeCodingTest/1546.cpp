#include <iostream>
using namespace std;

int main() {
	int n;
	int* arr;
	int max = 0;
	double result = 0;
	cin >> n;

    arr = new int[n];

	for (int i = 0; i < n; i++) {
        //변수 바로 할당 가능
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
		result += arr[i];
	}
	result = result / max * 100 / n;

	//cout << fixed;
	//cout.precision(6);
	cout << result << endl;
}