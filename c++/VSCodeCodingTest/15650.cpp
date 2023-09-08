#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];//정렬된 순열을 담는 배열
bool visited[MAX];//이미 방문된 숫자인지 판별하는 bool 배열

void DFS(int depth, int num)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++)
    {
        //중복 비허용
        if(!visited[i])
        {
            visited[i] = true;
            arr[depth] = i;
            DFS(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
  cin >> n >> m;
  DFS(0, 1);//깊이 0부터 DFS 시작
}