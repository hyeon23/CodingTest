// #include <bits/stdc++.h>
// using namespace std;

// //deque 해결법
// int main(){
//     int N;
//     cin >> N;
//     string car;
//     deque<string> q;
//     for(int i = 0; i < N; ++i){//대근
//         cin >> car;
//         q.push_back(car);
//     }
//     int cnt = 0;
//     for(int i = 0; i < N; ++i){//영식
//         cin >> car;

//         if(q.front() != car){
//             ++cnt;
//             q.erase(find(q.begin(), q.end(), car));
//         }
//         else{
//             q.pop_front();
//         }
//     }
//     cout << cnt;
// }

//정석 map 해결법
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	unordered_map<string, int> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		m[s] = i;
	}
	vector<string> v(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (m[v[i]] > m[v[j]]) {
				cnt += 1;
				break;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}