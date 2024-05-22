//최대 공약수, 최소 공배수
int gcd(int x, int y){
	if(x % y == 0){
		return y;
	}
	return gcd(y, x % y);
}

int lcm(int x, int y){
	return x * y / gcd(x, y);
}

//소수 구하기 알고리즘
bool isPrime(int n){
	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

//소수 구하기 알고리즘: 에라토스테네스의 체
int eratos(int n){
	int answer = 0;
	int num = 1000001;
	vector<bool> vec(1000001, true);
	v[0] = 0;//소수가 아님
	v[1] = 0;//소수가 아님
	//소수 판별
	for(int i = 2; i * i <= num; ++i){
		if(v[i]){
			for(int k = 2 * i; k <= num; k += i){
				v[k] = false;
			}
		}
	}
	for(int i = 1; i <= n; ++i) if(v[i]) ++answer;
	return answer;
}

//합집합
int totalSize = A.size() + B.size();
vector<string> uni(totalSize);
auto iterU = set_union(A.begin(), A.end(), B.begin(), B.end(), uni.begin());
uni.erase(iterU, uni.end());

//교집합
int totalSize = A.size() + B.size();
vector<string> inter(totalSize);
auto iterI = set_union(A.begin(), A.end(), B.begin(), B.end(), iterI.begin());
inter.erase(iterI, inter.end());

//차집합
int totalSize = A.size() + B.size();
vector<string> diff(totalSize);
auto iterD = set_dirrerence(A.begin(), A.end(), B.begin(), B.end(), diff.begin());
diff.erase(iterD, diff.end());

//BFS 2D  타일맵 도착지 찾기
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<vector<int>>& maps, pair<int, int> start){
    int csize = maps.size(); // 행(세로) 크기
    int rsize = maps[0].size(); //열(가로) 크기
    vector<vector<bool>> visited(csize, vector<bool>(rsize, false));

    queue<pair<int, int>> que;//bfs queue;
    que.push(start);//start pos insert

    int answer = 0;

    int dx[4] = {1, 0, -1, 0};//수직 이동
    int dy[4] = {0, 1, 0, -1};//수평 이동
    while(!que.empty()){
        //같은 거리 레벨의 노드를 한번에 처리하기 위함
        int size = que.size();
        for(int i = 0; i < size; ++i){
            pair<int, int> pos = que.front();
            que.pop();

            int cx = pos.first;
            int cy = pos.second;

            //도착점에 도달한 경우
            if(cx == csize - 1 && cy == rsize - 1) return answer + 1;

            if(visited[cx][cy]) continue;

            //현재 노드 방문 처리
            visited[cx][cy] = true;

            //상하좌우 이동
            for(int dir = 0; dir < 4; ++dir){
                int nx = cx + dx[dir]; // 다음 x
                int ny = cy + dy[dir]; // 다음 y

                //다음 이동 제한 위치
                if(nx < 0 || ny < 0 || nx >= csize || ny >= rsize || maps[nx][ny] != 1 || visited[nx][ny]) continue;

                que.push({nx, ny});
            }
        }
        ++answer;
    }
    return -1;
}

int solution(vector<vector<int>> maps){
    return bfs(maps, {0, 0});
}

//게임 맵 최단거리(DP)
#include <queue>
#include <vector>
using namespace std;

// BFS를 사용하여 최단 거리를 계산하는 함수
int bfs(vector<vector<int>>& maps, pair<int, int> start) {
    int csize = maps.size();  // 맵의 세로 크기 (행의 개수)
    int rsize = maps[0].size();  // 맵의 가로 크기 (열의 개수)
    vector<vector<int>> dp(csize, vector<int>(rsize, -1));  // 각 위치까지의 최단 거리를 저장하는 DP 배열

    queue<pair<int, int>> q;  // BFS를 위한 큐
    q.push(start);  // 시작 위치를 큐에 추가
    dp[start.first][start.second] = 1;  // 시작 위치의 거리를 1로 초기화

    int dx[4] = {1, 0, -1, 0};  //수직 이동
    int dy[4] = {0, 1, 0, -1};  //수평 이동

    while (!q.empty()) {
        pair<int, int> pos = q.front();  // 큐에서 위치를 꺼내고
        q.pop();  // 큐에서 제거
        int cx = pos.first;  // 현재 위치의 x 좌표
        int cy = pos.second;  // 현재 위치의 y 좌표

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];  // 새로운 x 좌표
            int ny = cy + dy[dir];  // 새로운 y 좌표

            // 맵 외부
            if(nx < 0 || ny < 0 ||  nx >= csize || ny >= rsize) continue;
            // 벽이 있는 자리 or 이미 방문한 경우
            if(maps[nx][ny] != 1 || dp[nx][ny] != -1) continue;

            dp[nx][ny] = dp[cx][cy] + 1;  // 최단 거리 갱신
            q.push({nx, ny});  // 다음 위치를 큐에 추가하여 탐색
        }
    }

    return dp[csize - 1][rsize - 1];  // 도착점까지의 최단 거리 반환
}

// 주어진 맵에서 최단 거리를 계산하는 함수
int solution(vector<vector<int>> maps) {
    return bfs(maps, {0, 0});  // bfs 함수 호출하여 결과 반환
}

//하노이 탑
#include <cmath>
#include <iostream>

void move(int start, int to){
    //move a to b
    cout << start << ' ' << to << '\n';
}

void hanoi(int n, int start, int to, int bypass){
    if(n == 1) move(start, to);
    else{
        hanoi(n-1, start, bypass, to);
        move(start, to);
        hanoi(n-1, bypass, to, start);
    }
}

int main(){
    int num;
    cin >> num;
    cout << (int)pow(2, num) - 1 << '\n';
    hanoi(num, 1, 3, 2);
}

//N-Queen
#include <iostream>
#define MAX 15
using namespace std;
int col[MAX];
int N, total = 0;

bool check(int curN){
    for(int i = 0; i < curN; ++i){
        //같은 행 or 같은 열 or 대각선상 위치
        if(i == curN || col[i] == col[curN] || abs(col[curN] - col[i]) == abs(curN - i)){
            return false;
        }
    }
    return true;
}

void N_Queen(int curN){
    //N_Queen - 퀸 배치
    if(curN == N){
        ++total;
        return;
    }
    for(int i = 0; i < N; ++i){
        col[curN] = i;
        if(check(curN))
            N_Queen(curN + 1);
    }
}

int main(){
    cin >> N;
    N_Queen(0);
    cout << total;
}

//우선순위 큐 우선순위 설정
struct cmp{
    //반대로 선언
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) 
            return a > b;
        return abs(a) > abs(b);
    }
};


int main(){
    priority_queue<int, vector<int>, cmp> pq;
}