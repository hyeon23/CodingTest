#include <iostream>
#include <vector>

using namespace std;

int main() {

	////sol1
	//int N, v;
	//cin >> N >> v;
	//int* a = new int[N];

	//for (int i = 0; i < N; ++i) {
	//	cin >> a[i];
	//}

	//for (int i = 0; i < N; ++i) {
	//	if (a[i] < v)
	//		cout << a[i] << " ";
	//}
	//return 0;

	int N, v;
	vector<int> vec;
	cin >> N >> v;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	for (int i = 0; i < N; ++i) {
		if (vec[i] < v)
			cout << vec[i] << " ";
	}
}