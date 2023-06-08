#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    //Tips: endl을 '\n'으로 쓰는 습관을 들이자!
    //성능을 높이기 위한 SET
    //1. ios_base::sync_with_stdio(0);
    //2. cin.tie(0);
    //3. cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; ++i)
        //cin >> vec[i];
        scanf_s("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < N; ++i){
        printf("%d\n", vec[i]);
    }
}