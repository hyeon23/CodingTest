#include <bits/stdc++.h>
using namespace std; 

int dx[4] = {0,0,-1,1}; 
int dy[4] = {-1,1,0,0}; 
int n; 
int board[11][11]; 
int visited[11][11]; 
int result = INT_MAX; 

void dfs(int sum, int cnt) {
	if (cnt == 3) {
		result = min(result, sum); 
        return; 
	}

    //현재점 = (i, j) 가정
    //다음점 = (nx, ny)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int check = 0; 
			int nx, ny;

			for (int k = 0; k < 4; k++) {
				nx = j + dx[k]; 
				ny = i + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;

				if (visited[ny][nx])continue;

				check++;
			}

            //상/하/좌/우 모두 이동 가능한 경우 (1,1) - (n-1,n-1)
			if (check == 4) {
				int ssum = board[i][j]; 

				for (int k = 0; k < 4; k++) {
					nx = j + dx[k];
					ny = i + dy[k];
					visited[ny][nx] = 1; 		
					ssum += board[ny][nx]; //5개 지점의 비용 합산
				}
				visited[i][j] = 1;
				sum += ssum; 
				cnt++; 

				dfs(sum, cnt); 

				sum -= ssum; 
				cnt--; 
				
				for (int k = 0; k < 4; k++) {
					nx = j + dx[k];
					ny = i + dy[k];
					visited[ny][nx] = 0;				
				}
				visited[i][j] = 0;
			
			}
		}
	}

}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j]; 
		}
	}

	dfs(0, 0);
	cout << result; 
}