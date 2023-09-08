// #include <iostream>
// #include <string>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <vector>

// //#시간초과
// using namespace std;
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int N, M;
//     cin >> N;
//     deque<long long> deqvec(N);
//     vector<int> qstype(N);
//     for(int i = 0; i < N; ++i)
//         cin >> qstype[i];
//     for(int i = 0; i < N; ++i)
//         cin >> deqvec[i];
//     cin >> M;
//     long long top;
//     for(int i = 0; i < M; ++i){
//         long long tmp;
//         cin >> top;
//         for(int j = 0; j < N; ++j){
//             if(!qstype[j]){//queue
//                 tmp = deqvec[j];
//                 deqvec[j] = top;
//                 top = tmp;
//             }
//         }
//         cout << top << ' ';
//     }
// }

#include <iostream>
#include <deque>
using namespace std;

deque<int> que;
bool arr[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (arr[i]) continue;
		que.push_back(x);
	}
    //1 2
    //4
	int M; cin >> M;
	while (M--) {
		int x; cin >> x;
		que.push_front(x);
		cout << que.back() << ' ';
		que.pop_back();
	}
}