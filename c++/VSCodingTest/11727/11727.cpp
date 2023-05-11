#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(3);

	for (int i = 2; i < N; i++) {
		dp.push_back((dp[i - 1] + dp[i - 2] * 2) % 10007);
	}

	cout << dp[N - 1];
}