/* 프렉탈 평면 */

/* 
아무리 복잡해보이는 프랙탈이라고 하더라도 처음에는 N * N으로 나눠지고 중간에 K * K만 검정색
예제의 결과물이 27 x 27의 거대한 평면 프랙탈이더라도 시작은 3 X 3에 가운데만 검정색
*/
#include <bits/stdc++.h>
#define WHITE 0
#define BLACK 1
using namespace std;
int Time, N, K, R1, R2, C1, C2, biggestFS;
int getColor(int r, int c) {
    int t_big = biggestFS;
    int tr = r, tc = c, pr, pc;
    while ((t_big /= N)!= 0) {            
        // 주어진 좌표값이 N X N으로 나누어진 칸 중 어디에 속하는 지 파악
        pr = tr / t_big;
        pc = tc / t_big;
        // 그 칸 안에서 K * K에 속하는 지 판단한다. 만약 속하면 BLACK을 return
        if (is_middle(pr, pc, t_big / N) == true) {
            return BLACK;
        }
        // 아니라면 계산의 대상을 그 칸 안으로 한정
        tr -= (pr * t_big);
        tc -= (pc * t_big);
    }
    return WHITE;
}
/*가운데 검정색인 K * K 영역을 판정하는 함수*/
/*curFs : 현재 프렉탈 사각형의 길이*/
bool is_middle(int r, int c, int curFS) {
    int sp = (N - K) / 2;
    int fp = sp + K;
    if((sp <= r && r < fp) && (sp <= c && c < fp))
        return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> Time >> N >> K >> R1 >> R2 >> C1 >> C2;
    /*FS : FractalSize*/
    /*biggestFS : 가장 큰 프렉탈 사각형의 길이*/
    // 시간을 모두 진행했을 때 각 행과 열의 칸의 개수.
    biggestFS = pow(N, Time);
    //출력을 희망하는 (i, j) 좌표에 대해 getColor(i, j) 함수를 통해 출력 여부 체크
    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << getColor(i, j);
        }
        cout << '\n';
    }
    return 0;
}