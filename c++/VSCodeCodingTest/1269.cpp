#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
//sol1: set 방식
//vector를 제외한 STL에서 binary_search보다 STL.find()의 기능이 월등히 좋음
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int N, M, temp, count = 0;
//     cin >> N >> M;
//     set<int> set1;
//     for(int i = 0; i < N; ++i){
//         cin >> temp;
//         set1.insert(temp);
//     }
//     for(int i = 0; i < M; ++i){
//         cin >> temp;
//         if(set1.find(temp) != set1.end()){
//             ++count;
//         }
//     }
//     cout << N + M - 2 * count;
// }
//sol2: map 방식
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, temp, count;
    cin >> N >> M;
    map<int, int> map;
    for(int i = 0; i < N; ++i){
        cin >> temp;
        map.insert({temp, 0});
    }
    for(int i = 0; i < M; ++i){
        cin >> temp;
        if(map.find(temp) != map.end()){
            ++count;
        }
    }
    cout << N + M - 2 * count;
}
//sol2: map 새로운 방식
int main(void)
{
    map<int, bool> m;
    int N,M;
    int num;
	cin >> N >> M;
	for (int i = 0; i < N+M; i++)
	{
		cin >> num;
		if (m[num] == true) // 이미 존재하면 map에서 제거를 한다.
			m.erase(num);
		else // 존재 안하면 추가를 해준다.
			m[num] = true;
	}
	cout << m.size(); // 남은 map 사이즈를 출력

}