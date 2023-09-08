#include <cmath>
#include <iostream>

using namespace std;

void hanoi(int n, int start, int to, int bypass){
	if(n == 1)
		cout << start << ' ' << to << '\n';
	else{
		hanoi(n-1, start, bypass, to);
		cout << start << ' ' << to << '\n';
		hanoi(n-1, bypass, to, start);
	}
}
int main(){
	int num;
	cin >> num;
	cout << (1 << num) - 1 << '\n'; 
	//1 << num = pow(2, num)
	//단, double 형을 사용하는 pow의 특성상 입력 최대값인 20 입력 시, 오차범위가 커져 오답
	//대안: (int)pow(2, num);
	hanoi(num, 1, 3, 2);
}