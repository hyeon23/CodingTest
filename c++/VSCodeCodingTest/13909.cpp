//메모리 초과

// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main(){
//     unsigned int N, cnt = 0;

//     cin >> N;

//     vector<bool> vec;

//     vec.assign(N, false);

//     for(int i = 1; i <= N; ++i)
//         for(int j = 1; i * j <= N; ++j)
//             vec[i * j - 1] = !vec[i * j - 1];

//     sort(vec.begin(), vec.end());

//     for(int i = 0; i < vec.size(); ++i){
//         if(vec[i] == true){
//             ++cnt;
//         }
//     }

//     cout << cnt;
// }

//창문 여닫이
//-창문이 열려 있다 -> 홀수번의 여닫이 필요
//-N번째 창문이 열려있기 위해선 N의 약수의 개수가 홀수여야 함
//-제곱수[i * i]: 약수의 개수가 홀수여야 수

//제곱수의 개념을 잘 이해해야 함
#include <iostream>
using namespace std;
int n, i;
int main() {
	cin >> n;
	while (i * i <= n) i++;
	cout << i - 1 << endl;
}