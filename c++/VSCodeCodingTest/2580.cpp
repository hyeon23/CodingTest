// 스도쿠 풀이
// 각 행, 열, 3 X 3 크기 구역 9개에 각 1 ~ 9 까지 숫자가 단 한번씩 들어가야 함
// 스도쿠 유효성 check 함수 필요
// check: 같은 행 or 열에 같은 숫자가 있는지, 3 X 3 크기의 구역에 같은 숫자가 있는지 체크
// 백트래킹을 통해 0이 입력된 빈칸 부분에 1 ~ 9까지의 숫자를 차례로 넣음
// 모든 칸을 채웠을 때, 결과 도출

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int board[9][9];               // 스도쿠 보드 선언
vector<pair<int, int>> points; // 빈칸 위치 저장
int cnt = 0;
bool found = false; // 스도쿠 판 완성 플래그

bool check(pair<int, int> p)
{
    // 스토쿠 유효성 판정 함수
    // 구역을 3개로 나눔
    int square_x = p.first / 3;
    int square_y = p.second / 3;

    // 행렬 체크
    for (int i = 0; i < 9; ++i)
    {
        // 행 체크(같은 행에 같은 숫자가 있으면 false 반환)
        if (board[p.first][i] == board[p.first][p.second] && i != p.second)
            return false;

        // 열 체크(같은 열에 같은 숫자가 있으면 false 반환)
        if (board[i][p.second] == board[p.first][p.second] && i != p.first)
            return false;
    }

    // 3X3 구역 체크
    //-> 속한 구역(0, 1, 2) * 3 ~ (0, 1, 2) * 3 + 3
    // 0 1 2 / 3 4 5 / 6 7 8
    for (int i = 3 * square_x; i < 3 * square_x + 3; ++i)
        for (int j = 3 * square_y; j < 3 * square_y + 3; ++j)
        {
            if (board[i][j] == board[p.first][p.second])
            {
                // 같은 구역에 같은 숫자가 있는 경우 false 반환
                if (i != p.first && j != p.second)
                    return false;
            }
        }
    return true; // 모든 조건 만족시, 유효성 검사 통과
}

void sudoku(int N)
{
    if (N == cnt)
    { // 빈 칸의 개수만큼 채워 스도쿠판이 완성되면
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        found = true;
        return;
    }

    // 스도쿠 판이 완성되지 않은 상황
    for (int i = 1; i <= 9; ++i)
    {
        // 1 ~ 9까지의 숫자를 넣어봄
        board[points[N].first][points[N].second] = i;

        if (check(points[N])) // 결과가 유효하면 다음 빈칸을 채움
            sudoku(N + 1);

        if (found) // 스도쿠가 완성된 경우, 다른 해를 탐색할 필요 X
            return;
    }
    board[points[N].first][points[N].second] = 0;
    return;
}

int main()
{
    pair<int, int> point;
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                cnt++;
                point.first = i;
                point.second = j;
                points.push_back(point); // 빈칸 위치 배열에 빈칸 저장
            }
        }
    sudoku(0);
    // 백트래킹은 반드시 0부터(or N) 호출
    // 자동으로 N(or 0)까지 호출되도록 개발
}