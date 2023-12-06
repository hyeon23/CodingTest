#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};

int nx, ny;

int dx[] = {-1,0,1,1};
int dy[] = {1,1,1,0};

void bfs(int x, int y, int st_x, int st_y, int num, int dir){
    visited[x][y] = true;
    
    for(int i = 0; i < 4; ++i){
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx >= 1 && ny >= 1 && nx <= 19 && ny <= 19 && !visited[nx][ny] && (arr[x][y] == arr[nx][ny])){
            if(x == nx){//세로
                if(dir==1) bfs(nx, ny, st_x, st_y, num+1, dir);
                else bfs(nx, ny, x, y, 2, 1);
            }
            else if(y == ny){//가로
                if(dir==2) bfs(nx, ny, st_x, st_y, num+1, dir);
                else bfs(nx, ny, x, y, 2, 2);
            }
            else if(y-ny == 1 && nx - x == 1){//위 대각
                if(dir==3) bfs(nx, ny, st_x, st_y, num+1, dir);
                else bfs(nx, ny, x, y, 2, 3);
            }
            else {//아래 대각
                if(dir==4) bfs(nx, ny, st_x, st_y, num+1, dir);
                else bfs(nx, ny, x, y, 2, 4);
            }
        }
    }
    visited[x][y] = false;

    if(num == 5){
        if(dir == 1) if((y > 5 && arr[x][y] == arr[x][y-5]) || (y < 19 && arr[x][y] == arr[x][y+1])) return;
        else if(dir == 2) if((x > 5 && arr[x][y] == arr[x-5][y]) || (x < 19 && arr[x][y] == arr[x+1][y])) return;
        else if(dir == 3) if((x < 15 && y > 5 && arr[x][y] == arr[x+5][y-5]) || (x > 1 && y < 19 && arr[x][y] == arr[x-1][y+1])) return;
        else if(dir == 4) if((x > 5 && y > 5 && arr[x][y] == arr[x-5][y-5]) || (x < 19 && y < 19 && arr[x][y] == arr[x+1][y+1])) return;
        cout << arr[x][y] << '\n' << st_y << " " << st_x << '\n';
        exit(0);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 19; ++i){
        for(int j = 1; j <= 19; ++j){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= 19; ++i){
        for(int j = 1; j <= 19; ++j){
            if((arr[i][j] == 1 || arr[i][j] == 2) && !visited[i][j]) bfs(i, j, i, j, 1, 0);
        }
    }
    
    cout << 0 << '\n';
    return 0;
}