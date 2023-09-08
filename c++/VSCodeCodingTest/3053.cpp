#include <math.h>
#include <iostream>
//내가 파이 몇자리까지를 어캐 알어;[인터넷 복붙]
#define PI 3.1415926535897932
using namespace std;

int main(){
    double R;
    cin >> R;

    cout << fixed;
	cout.precision(6);
    cout << R * R * PI << '\n';
    cout << R * R * 2 << '\n';
}