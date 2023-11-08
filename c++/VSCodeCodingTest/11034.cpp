#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int A, B, C;

    while(cin >> A >> B >> C){
        int cnt = 0;

        while(abs(B - A) >= 2 || abs(C - B) >= 2){
            cnt++;
            if(abs(B - A) >= 2 && abs(C - B) >= 2){
                if(abs(B - A) > abs(C - B) >= 2){
                    //C를 A와 B 사이로 // 2 4 5
                    int tmp = B-1;
                    C = tmp;
                    swap(B, C);
                }
                else{
                    //A를 B, C 사이로 //2 3 5
                    int tmp = B+1;
                    A = tmp;
                    swap(A, B);
                }
            }
            else if(abs(B - A) >= 2){
                //C를 A와 B 사이로 // 2 4 5
                int tmp = B-1;
                C = tmp;
                swap(B, C);
            }
            else if(abs(C - B) >= 2){
                //A를 B, C 사이로 //2 3 5
                int tmp = B+1;
                A = tmp;
                swap(A, B);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}