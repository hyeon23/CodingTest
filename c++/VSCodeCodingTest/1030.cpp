/* 프렉탈 평면 */
#include <iostream>
#include <cmath>
#define WHITE 0
#define BLACK 1
using namespace std;
int Time, N, K, R1, R2, C1, C2, Biggest;

int getColor(int r, int c);
bool is_middle(int r, int c, int);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> Time >> N >> K >> R1 >> R2 >> C1 >> C2;

    Biggest = pow(N, Time);             
    // 시간을 모두 진행했을 때 각 행과 열의 칸의 개수.
    // 만약 N이 3이고 이 과정을 3번 진행했다면 전체 칸의 개수는 27이다 (3의 3제곱)
    // 예제가 딱 그런 케이스 

    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << getColor(i, j);
        }
        cout << '\n';
    }

    return 0;
}

/* 
아무리 복잡해보이는 프랙탈이더라도 처음에는 N * N으로 나눠지고 중간에 K * K만 검정색
즉 예제의 결과물이 27 x 27의 거대한 평면 프랙탈이라고 하더라도 시작은 3 X 3에 가운데만 검정색이었다.
그러므로 우린 그 과정을 따라간다.*/
int getColor(int r, int c) {
    int t_big = Biggest;
    int tr = r, tc = c, pr, pc;
    while ((t_big /= N)!= 0) {            
        // 주어진 좌표값이 N X N으로 나누어진 칸 중 어디에 속하는 지 파악한다. 
        pr = tr / t_big;
        pc = tc / t_big;

        // 그 칸 안에서 K * K에 속하는 지 판단한다. 만약 속하면 BLACK을 return 한다. 
        if (is_middle(pr, pc, t_big / N)) {
            return BLACK;
        }

        // 아니라면 이제 계산의 대상을 그 칸 안으로 한정시킨다. 
        tr -= (pr * t_big);
        tc -= (pc * t_big);
    }
    return WHITE;
}

// 가운데에 있는 K * K의 검정색 영역을 판정하는 함수
// t_big이 갱신되며 pr(r), pc(c)의 범위는 0 to 각 프렉탈의 한 변의 길이 - 1로 고정
bool is_middle(int r, int c, int k) {  
    int sp = (N - K) / 2;
    int fp = sp + K;
    if((sp <= r && r < fp) && (sp <= c && c < fp)) return true;
    return false;
}