#include <iostream>
using namespace std;

//최대공약수
long long gcd(long long n, long long m)
{
	if (n % m == 0)
		return m;
    else
	    return gcd(m, n % m);
}

//최소공배수
long long lcm(long long n, long long m)
{
	return n * m / gcd(n, m);
}

int main()
{
	long long a, b;
		
	cin >> a >> b;
		
	cout << lcm(a, b) << endl;
	return 0;
}
