#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	long long x, y;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		double dist = y - x;		 // 두 지점 사이의 거리
		double dpow = sqrt(dist);	 // 거리의 제곱근
		int pow = round(sqrt(dist)); // 거리의 제곱근의 반올림

		// 거리의 제곱근과 제곱근의 반올림을 비교
		//  < : 2 * pow - 1 = 이동횟수
		//  = : 2 * pow - 1 = 이동횟수
		//  > : 2 * pow = 이동횟수
		if (dpow <= pow)
			cout << pow * 2 - 1 << "\n";
		else
			cout << pow * 2 << "\n";
	}

	return 0;
}