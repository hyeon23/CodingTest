#include <iostream>
using namespace std;
#define MAX 1000000

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    //에라토스테네스의 체
    int arr[MAX + 1]{0,};

    for(int i = 2; i <= MAX; ++i){
        arr[i] = i;
    }

    for(int i = 2; i * i <= MAX; ++i){
        if(arr[i] == 0)
            continue;

        for(int j = i * i; j <= MAX; j += i)
            arr[j] = 0;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt(0);
        //GoldBach Partition
        for(int i = 2; i < n; ++i){
            if(arr[n-i] + arr[i] == n){//서로 다룬 수 2가지 조합
                cnt++;
                if(n - i == i){//서로 같은 경우 2가지 조합
                    cnt++;
                }
            }
        }
        cout << cnt / 2 << '\n';
    }
}