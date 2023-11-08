#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	bool eratosthenes[1000001] = {false,false}; // 소수:true, 소수X;false
	vector<int> v;
	
	for (int i = 2; i < 1000001; i++)	//2부터 끝까지 소수로 가정
		eratosthenes[i] = true;
	
	for (int i = 0; i*i < 1000001; i++) {	//소수x인거 false로 바꾸기
		if (eratosthenes[i] == true) {	//소수로 가정한것 차례대로 검사
			for (int j = i*i; j < 1000001; j += i) //i의 제곱부터 i만큼 더하면 소수x
				eratosthenes[j] = false;
		}
	}

	for (int i = 0; i < 1000001; i++) {
		if (eratosthenes[i] == true)	//소수 벡터에 넣기
			v.push_back(i);
	}

	int n;
	long long int m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < v.size(); j++) {
			if (m % v[j] == 0)	//1000000 보다 작은 소수로 나누어지는 경우
			{
				cout << "NO\n";
				m = 0;
				break;
			}
		}
		if (m != 0) //1000000 보다 큰 소수인 경우
			cout << "YES\n";
	}

	system("pause");
	return 0;
}