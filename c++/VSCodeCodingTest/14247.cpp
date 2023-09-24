// #include <bits/stdc++.h>
// using namespace std;

// bool cmp(pair<long long, long long> A, pair<long long, long long> B){
//     if(A.second == B.second){
//         A.first > B.first;
//     }
//     return A.second < B.second;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     long long n;
//     cin >> n;
//     vector<pair<long long, long long>> trees(n);//높이, 성장률

//     for(long long i = 0; i < n; ++i)
//         cin >> trees[i].first;
//     for(long long i = 0; i < n; ++i)
//         cin >> trees[i].second;

//     sort(trees.begin(), trees.end(), cmp);

//     long long sum = 0;

//     for(long long i = 0; i < n; ++i){
//         sum += trees[i].first;
//         for(long long j = i+1; j < n; ++j){
//             trees[j].first += trees[j].second;
//         }
//     }

//     cout << sum;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
    vector<pair<int,ll>> tree(n);

	for(int i=0;i<n;++i) cin>>tree[i].second;
	for(int i=0;i<n;++i) cin>>tree[i].first;
	sort(tree.begin(),tree.end());

	ll yang=0;
	for(int i=0;i<n;++i){
		yang += tree[i].second + tree[i].first * i;
	}
	cout<<yang;
}