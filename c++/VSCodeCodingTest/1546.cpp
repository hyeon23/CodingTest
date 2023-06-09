#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// int main() {
// 	int n;
// 	int* arr;
// 	int max = 0;
// 	double result = 0;
// 	cin >> n;

//     arr = new int[n];

// 	for (int i = 0; i < n; i++) {
//         //변수 바로 할당 가능
// 		cin >> arr[i];
// 		if (arr[i] > max)
// 			max = arr[i];
// 		result += arr[i];
// 	}
// 	result = result / max * 100 / n;

// 	//cout << fixed;
// 	//cout.precision(6);
// 	cout << result << endl;
// }

int main(){
	int N;
	double sum, M;
	cin >> N;
	vector<double> vec(N, 0);
	for(int i = 0; i < N; ++i){
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	M = vec[vec.size() - 1];
	for(int i = 0; i < vec.size(); ++i){
		sum += vec[i] / M * 100;
	}
	cout << fixed;
	cout.precision(6);
	cout << sum / vec.size();
}