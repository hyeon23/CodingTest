#include <iostream>
#include <string>

using namespace std;

int main() {
	//sol1
	//int A, B;
	//int a, b, c;

	//cin >> A;
	//cin >> B;

	//a = B % 10;//5
	//b = B % 100 - a;//80
	//c = B - b - a;//300

	//cout << A * a << endl;
	//cout << A * b / 10 << endl;
	//cout << A * c / 100 << endl;
	//cout << A * B << endl;
	
	//sol2
	//int A;
	//char B[4];

	//cin >> A;
	//cin >> B;

	////char - '0' = int�� �ȴ�.
	//// char ch1 = '1';
	////int numAscii = (int)ch1; �ƽ�Ű �ڵ带 ���� ���� ��� (int)�� ����ȯ

	//cout << A * (B[2] - '0') << endl;
	//cout << A * (B[1] - '0') << endl;
	//cout << A * (B[0] - '0') << endl;
	//cout << A * atoi(B) << endl;

	int A;
	string B;
	cin >> A;
	cin >> B;

	cout << A * (B[2] - '0') << '\n';
	cout << A * (B[1] - '0') << '\n';
	cout << A * (B[0] - '0') << '\n';
	cout << A * stoi(B) << '\n';
}