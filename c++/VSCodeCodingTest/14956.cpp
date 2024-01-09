#include <bits/stdc++.h>
using namespace std;

pair<int , int> hilbert(int N, int M){
    //배열 좌표계가 아닌 일반 좌표계 사용(y축 대칭)
    pair<int, int> p;//x, y
    //base condition : W1
    if(N == 2){
        switch(M){
            case 0://좌하단
                p = {1,1};
                return p;
            case 1://좌상단
                p = {1,2};
                return p;
            case 2://우상단
                p = {2,2};
                return p;
            case 3://우하단
                p = {2,1};
                return p;
        }
    }

    int half = N/2;
    int quadrant = M / (half*half);
    switch(quadrant){
        //좌하단
        case 0:
            p = hilbert(half, M % (half * half));
            swap(p.first, p.second);
            return p;
        //좌상단
        case 1:
            p = hilbert(half, M % (half * half));
            p.second += half;
            return p;
        //우상단
        case 2:
            p = hilbert(half, M % (half * half));
            p.first += half;
            p.second += half;
            return p;
        //우하단
        case 3:
            p = hilbert(half, M % (half * half));
            pair<int, int> temp = {2 * half - p.second + 1, half - p.first + 1};
            return temp;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    pair<int, int> result = hilbert(N, M-1);
    cout << result.first << ' ' << result.second << '\n';
    return 0;
}