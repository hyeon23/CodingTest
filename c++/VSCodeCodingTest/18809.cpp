//하늘색 칸(0) : 호수
//하얀색 칸(1) : 배양액을 뿌릴 수 없는 땅
//황토색 칸(2) : 배양액을 뿌릴 수 있는 땅
//초록색 배양액 & 빨간색 배양액이 동일한 시간에 도달한 경우
///-꽃이 피어나고, 배양액이 사라짐
//-배양액 퍼짐이 멈춤
//-배양액은 남기지 않고 모두 사용해야 함
//-모든 배양액은 서로 다른 곳에 뿌려져야함
#include <bits/stdc++.h>
using namespace std;
int N, M, G, R;
vector<vector<int>> board(51, vector<int>(51));

void DFS(int depth){
    if(depth == G + R){
        return;
    }
    for(int i = 0; i < N + M; ++i){
        DFS(depth+1);
    }
    return;
}
int main(){
    cin >> N >> M >> G >> R;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> board[i][j];
        }
    }
    vector<int> comb(N * M, 0);
    fill(comb.begin(), comb.begin() + G, 2);//Green 배양액 = 2
    fill(comb.begin()+G, comb.begin() + G + R, 1);//Red 배양액 = 1
    //배양액의 위치를 뽑고, 해당 위치에 대해 BFS 탐색을 통해 겹침검사?
    //뭐 이런식으로 풀면 되려남..
    //6 X 6 = 36 1차원 배열로 조합을 표현해서 2차원 배열 board에 할당
    //뭐 이런식으로 하면 되려남..
    DFS(0);
    return 0;
}