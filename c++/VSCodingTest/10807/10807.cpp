#include <iostream>
#include <vector>

using namespace std;

int main() {
	//sol1
	/*int N, v;
	vector<int> vec;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	cin >> v;

	int vCount = 0;

	for (int i = 0; i < vec.size(); ++i) {
		if (v == vec[i])
			vCount++;
	}

	cout << vCount;*/

	//sol2
	int N, v;
	cin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	cin >> v;
	int count = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] == v) {
			count++;
		}
	}

	cout << count;

	return 0;
}