#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    //sol1: Hashmap(unordered_map)을 이용한 풀이
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int, int> m;
    int N, M, card;      
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> card;
        m[card]++;
    }  
    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> card;
        cout << m[card] << " ";
    }
}

int main(){
    //sol2: 이분탐색을 이용한 풀이(sort, lower_bound, upper_bound)
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[500002];
    int N, M, card;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> card;
        arr[i] = card;
    }
    sort(arr, arr + N);

    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> card;
        cout << upper_bound(arr, arr+N, card) - lower_bound(arr, arr+N, card) << " ";
    }
}