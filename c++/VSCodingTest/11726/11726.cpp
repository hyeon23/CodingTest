#include <iostream>
#include <vector>

using namespace std;

//점화식에 대한 문제(주의)
int main() {
	int N;
	cin >> N;

	vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);

	for (int i = 2; i < N; i++)
	{
		dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
	}

	cout << dp[N - 1];

	return 0;
}