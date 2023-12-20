#include<bits/stdc++.h.>
using namespace std;
int T, h, w;
vector<string> board;
vector<vector<bool>> visited(101, vector<bool>(101, false));
set<char> keys;
void bfs(int x, int y){
    return;
}
int main(){
    //상근이가 훔칠 수 있는 문서의 최대 개수
    cin >> T;
    string tmp;
    while(T--){
        cin >> h >> w;
        for(int i = 0; i < h; ++i){
            cin >> tmp;//. = 빈공간 / * = 벽(이동불가) / $ = '훔처야 하는 문서' / 대문자 = 문 / 소문자 = 열쇠
            board.push_back(tmp);
        }
        cin >> tmp;
        if(tmp != "0"){
            for(auto c : tmp){
                keys.insert(c);
            }
        }
        
        //가장자리에서 BFS 탐색 수행
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(!(i == 0 || j == 0 || i == h-1 || j == w-1)) continue;
                //해당 지역에서 bfs 수행
                //방문하지 않았고, . or 키가 있는 알파벳의 경우
                if(!visited[i][j]){
                    //.가 있는 경우 -> 방문 처리 후 bfs 탐색
                    if(board[i][j] == '.'){
                        visited[i][j] = true;
                        bfs(i, j);
                    }
                    //소문자 = 키인 경우 -> 열쇠 주운 후 bfs 탐색
                    else if(islower(board[i][j])){

                    }
                    //대문자 = 문인 경우 -> 열쇠 유무 확인 후 처리
                    else if(isupper(board[i][j])){

                    }
                }
            }
        }
    }
    return 0;
}