#include <bits/stdc++.h>
using namespace std;

int main(){
    //논문의 중요도 = n편의 논문 중 k번 이상 인용된 논문이 k편 이상 & 나머지 n - k편의 논문들의 인용 횟수가 k번 이하
    //-> q 인덱스 = k
    
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for(int i = vec[0]; i <= vec[vec.size()-1]; ++i){
        //3 4 5 8 10

        int curqidx = i;
    }

    return 0;
}