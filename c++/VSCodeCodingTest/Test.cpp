#include <queue>
#include <vector>
using namespace std;


int dx[4] = {0, 0, 1, -1};  // x 방향 이동값 (상하좌우)
int dy[4] = {1, -1, 0, 0};  // y 방향 이동값 (상하좌우)

// BFS를 사용하여 최단 경로를 찾는 함수
int bfs(vector<vector<int>>& maps, pair<int, int> start) {
    int answer = 0;  // 결과값 (도착까지의 최단 거리)
    int csize = maps.size();  // 행의 크기 (세로 길이)
    int rsize = maps[0].size();  // 열의 크기 (가로 길이)
    vector<vector<bool>> visited(csize, vector<bool>(rsize, false));  // 방문 여부를 기록하는 배열
    queue<pair<int, int>> q;  // BFS를 위한 큐
    q.push(start);  // 시작 위치를 큐에 추가
    while (!q.empty()) {  // 큐가 비어있지 않은 동안 반복
        int size = q.size();  // 현재 큐의 크기 (같은 거리 레벨의 노드들을 한 번에 처리하기 위함)
        for (int i = 0; i < size; i++) {
            pair<int, int> pos = q.front();  // 큐에서 노드를 꺼내서
            q.pop();  // 큐에서 제거
            int x = pos.first;  // 현재 위치의 x 좌표
            int y = pos.second;  // 현재 위치의 y 좌표
            // 도착점에 도달한 경우
            if (x == csize - 1 && y == rsize - 1)
                return answer + 1;  // 결과값에 1을 더한 후 반환 (도착점까지의 거리)
            // 이미 방문한 경우 무시
            if (visited[x][y])
                continue;
            visited[x][y] = true;  // 현재 위치 방문 처리
            // 상하좌우로 이동하면서 갈 수 있는 곳을 큐에 추가
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];  // 새로운 x 좌표
                int ny = y + dy[dir];  // 새로운 y 좌표
                // 맵 내부이고, 벽이 아니며, 방문하지 않은 곳인 경우 큐에 추가
                if (nx >= 0 && nx < csize && ny >= 0 && ny < rsize && maps[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});  // 다음 위치를 큐에 추가
                }
            }
        }
        answer++;  // 레벨(거리)을 1 증가시킴
    }
    return -1; // 도착점에 도달하지 못한 경우
}

// 주어진 맵에서 최단 경로의 길이를 찾는 함수
int solution(vector<vector<int>> maps) {
    return bfs(maps, {0, 0});  // bfs 함수 호출하여 결과 반환
}