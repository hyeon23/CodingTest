#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);

    //sol1: binary_search & vector<pair<int, int>>를 이용한 풀이
    //-vector<pair<int, int>>는 map과 유사
    // int N, M;
    // cin >> N;
    // vector<int> vec1(N);
    // for(int i = 0; i < N; ++i)
    //     cin >> vec1[i];
    // cin >> M;
    // vector<pair<int, int>> vec2;
    // for(int i = 0; i < M; ++i){
    //     int x;
    //     cin >> x;
    //     vec2.push_back({x, 0});
    // }
    // sort(vec1.begin(), vec1.end());
    // for(int i = 0; i < vec2.size(); ++i){
    //     if(binary_search(vec1.begin(), vec1.end(), vec2[i].first))
    //         cout << 1 << " ";
    //     else
    //         cout << 0 << " ";
    // }
    // return 0;

    //sol2: set를 이용한 풀이
	set<int> card;
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		card.insert(num);
	}
	int M; 
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		if (card.find(num) != card.end()) cout << "1 ";
		else cout << "0 ";
	}
	return 0;
}