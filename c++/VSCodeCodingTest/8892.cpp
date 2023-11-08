#include<iostream>
#include<string>
using namespace std;
string s[100];
void func1();
bool func2(string x);
int k;

int main()
{
	cin.tie(0); cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		func1();
	}
}

bool func2(string x)
{
	for (int i = 0; i < x.size() / 2; i++)
	{
		if (x[i] != x[x.size() - i - 1])
			return false;
	}
	return true;
}
void func1()
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> s[i];

	for (int i = 0; i < k ; i++)
	{
		for (int j = 0; j < k; j++)
		{
			//i==j면 같은 글자이므로 절대 불가능
			if (i == j) continue;
			//팰린드롬이면
			if (func2(s[i] + s[j]))
			{
				cout << s[i] + s[j] << '\n';
				return;
			}
		}
	}
	//다 비교했는데도 팰린드롬아니면 0출력
	cout << 0 << '\n';
}