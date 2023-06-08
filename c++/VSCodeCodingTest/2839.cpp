#include <iostream>
#include <vector>
#include <string>

using namespace std;

// sol1: mysol
//  int main(){
//      int N;
//      int minv = 10000;
//      bool flag = false;
//      cin >> N;

//     for(int i = N / 5; i >= 0; --i){
//         int tempN = N;

//         tempN -= 5 * i;

//         if(tempN == 0){
//             minv = min(minv, i);
//             break;
//         }

//         for(int j = tempN / 3; j > 0; --j){
//             tempN -= 3 * j;

//             if(tempN == 0){
//                 minv = min(minv, i + j);
//             }
//         }
//     }

//     if(minv == 10000){
//         cout << -1;
//     }
//     else{
//         cout << minv;
//     }
// }

// sol2: greedy sol
int main() {
    int N;
	cin >> N;
	int ans = 0;
	while (N>=0) {
		if (N % 5 == 0) {
			ans += (N / 5);	//나눈 몫을 더한 것이 정답
			cout << ans << endl;
			return 0;
		}
		N -= 3;	//3kg을 빼고
		ans++;	//가방 하나 늘어남
	}
	cout << -1 << endl;
}