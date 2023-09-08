#include <bits/stdc++.h>
using namespace std;

vector<deque<int>> decks(2);
vector<deque<int>> grounds(2);

int win_check() {
    if(grounds[0].size() && grounds[0].front() == 5) return 0;
    if(grounds[1].size() && grounds[1].front() == 5) return 0;
    if(grounds[0].size() && grounds[1].size() && grounds[0].front() + grounds[1].front() == 5) return 1;
    return -1;
}

int main(){
    //N장 카드 도도덱
    //N장 카드 수연덱
    //그라운드는 최초 비워져있음
    //도도 -> 수연이 차례로 자신의 덱 가장 위 카드를 내려놓음
    //좋을 침(종 치는 사람이 카드 더미를 모두 가저감)
    //종 치는 조건
    //1. 그라운드에 나온 카드 더미의 가장 위 카드의 숫자 합이 5가 되는 순간 수연이가 종침
    //(둘다 비지 않아야 함) 5 X 종치기 이런거 없다는 소리
    //그라운드 나와있는 카드 더미 중 가장 위 카드 숫자가 5가 나오면 도도가 종을 침
    //종친 후, 상대 그라운드의 카드 더미를 뒤집어 자신의 덱 아래로 그대로 합친 후, 자신의 그라운드 카드 더미 역시 뒤집어 내 댁 아래로 그대로 가져와 합침
    //5. 한명이 2 ~ 4 과정을 진행하는 것을 1번 진행한 것으로 봄

    //게임 승패 결정 요건
    //1. 게임 진행 도중 자신의 덱의 카드의 수가 0개가 되면 상대방의 승리
    //2. M번 진행한 후, 자신의 덱에 더 많은 카드를 지닌 사람이 승리
    //3. M번 진행 후, 각자 덱에 카드의 개수가 같으면 비긴것으로 봄

    int N, M, d, s;
    cin >> N >> M;

    for(int i = 1; i <= N; ++i){
        cin >> d >> s;
        decks[0].push_back(d);
        decks[1].push_back(s);
    }
    //do: 1 2 1
    //su: 2 2 1

    //처리

    int turn = 0;

    for(int i = 0; i < M; ++i){
        grounds[turn].push_back(decks[turn].back());
        decks[turn].pop_back();

        if(decks[turn].empty()) {
            cout << (turn ? "do" : "su") << '\n';
            return 0;
        }

        int w = win_check();

        if (w != -1) {
            int l = 1 - w;
            while (grounds[l].size()) {
                decks[w].push_back(grounds[l].back());
                grounds[l].pop_back();
            }
            while (grounds[w].size()) {
                decks[w].push_back(grounds[w].back());
                grounds[w].pop_back();
            }
        }
        turn = 1 - turn;
    }

    if(decks[0].size() > decks[1].size()) cout << "do" << '\n';
    else if(decks[0].size() < decks[1].size()) cout << "su" << '\n';
    else cout << "dosu" << '\n';
}