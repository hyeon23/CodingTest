#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, S;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; ++i) cin >> vec[i];
    cin >> S;
    
    int start = 0;

    while(start < N && S > 0){
        //S번 이내의 swap으로 끌어올 수 있는 가장 큰 값을 A[start]로 끌어오기
        int maxIdx = start;

        for(int i = start; i <= min(N-1, start+S); ++i){
            if(vec[maxIdx] < vec[i]) maxIdx = i;
        }

        for (int i=maxIdx; i>start; i--) {
            swap(vec[i], vec[i-1]);
            S--;
        }
        
        start++;
    }
    for(int i = 0; i < vec.size(); ++i) cout << vec[i] << ' ';
    return 0;
}