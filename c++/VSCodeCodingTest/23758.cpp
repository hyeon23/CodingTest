#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>;
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    int vec[N];
    for(int i = 0; i < N; ++i) cin >> vec[i];
    sort(vec, vec + N);
    int result = 0;
    for(int i = 0; i < (N+1)/2; ++i) result += (int)log2(vec[i]);
    cout << result + 1;
}