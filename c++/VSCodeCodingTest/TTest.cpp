#include <queue>
#include <vector>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int bfs(vector<vector<int>>& maps, pair<int, int> start){
    int answer = 0;
    int csize = maps.size();
    int rsize = maps[0].size();
    vector<vector<bool>> visited(csize, vector<bool>(rsize, false));
    //bfs
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < q.size(); ++i){
            pair<int, int> pos = q.front();
            q.pop();
            int cx = pos.first;
            int cy = pos.second;
            if(cx == csize-1 && cy == rsize-1) return ++answer;
            if(visited[cx][cy]) continue;
            visited[cx][cy] = true;
            for(int dir = 0; dir < 4; ++dir){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(nx < 0 || ny < 0 || nx >= csize || ny >= rsize) continue;
                if(maps[nx][ny] == 0 || visited[nx][ny]) continue;
                q.push({nx, ny});  // 다음 위치를 큐에 추가
            }
        }
        ++answer;
    }
    return -1;
}
int solution(vector<vector<int>> maps){
    return bfs(maps, {0, 0});
}