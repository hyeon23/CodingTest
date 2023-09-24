#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, tmp;
        cin >> N;
        vector<int> vec(N);
        for(int i = 0; i < N; ++i) cin >> vec[i];
        sort(vec.begin(), vec.end(), greater<int>());
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            if(i % 2 == 0) dq.push_front(vec[i]);
            else dq.push_back(vec[i]);
        }
        dq.push_back(dq[0]);
        int dif = 0;
        for(int i = 1; i <= N; ++i){
            dif = max(dif, abs(dq[i] - dq[i-1]));
        }
        cout << dif << '\n';
    }

    

    return 0;
}

//Ver2 : Vector 구현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector <int> v(N);

		for (int i = 0; i < N; i++) cin >> v[i];

		sort(v.begin(), v.end());

		int result = 0;
		result = max(v[1] - v[0], v[N - 1] - v[N - 2]);//순환 시, 연결 부분 값

		for (int i = 1; i < N - 1; i++) {
			result = max(result, v[i + 1] - v[i - 1]);//비 순환 시, 값
		}
		cout << result << '\n';
	}
}