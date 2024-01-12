// #include <bits/stdc++.h>
// using namespace std;
// int N, d, w, ans = 0;
// vector<pair<int, int>> eggs;
// vector<bool> is_broken(9);
// vector<bool> is_visited(9);
// //가장 왼쪽 에그를 드는 행위
// void DFS(int cur_egg_idx){    
//     //1. 가장 오른쪽 에그를 들 경우 리턴
//     if(cur_egg_idx == N){
//         int cnt = 0;
//         for(auto e : is_broken){
//             if(e) ++cnt;
//         }
//         ans = max(ans, cnt);
//         return;
//     }
//     //2. 재귀를 통해 모든 에그에 대해 깨지지 않은 현재 들고있지 않은 egg 선택

//     if(is_broken[cur_egg_idx]){
//         DFS(cur_egg_idx+1);
//     }
//     else{
//         int num = 0;
//         for(int i = 0; i < N; ++i){
//         //현재 계란이 깨진 상태라면 다음 단계 진행
//             if(cur_egg_idx != i && !is_broken[i]){
//                 ++num;
//                 eggs[cur_egg_idx].first -= eggs[i].second;
//                 eggs[i].first -= eggs[cur_egg_idx].second;
//                 if(eggs[cur_egg_idx].first <= 0) is_broken[cur_egg_idx] = true;
//                 if(eggs[i].first <= 0) is_broken[i] = true;
//                 DFS(cur_egg_idx+1);
//                 if(eggs[cur_egg_idx].first <= 0) is_broken[cur_egg_idx] = false;
//                 if(eggs[i].first <= 0) is_broken[i] = false;
//                 eggs[cur_egg_idx].first += eggs[i].second;
//                 eggs[i].first += eggs[cur_egg_idx].second;
//             }
//         }
//         if(num == 0){
//             DFS(cur_egg_idx+1);
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     //계란 (내구도, 무게)
//     //계란 충돌 시, 상대 계란의 무게만큼 내구도가 깎임
//     //내구도 0 이하가 되는 순간 깨짐
//     cin >> N;
//     for(int i = 0; i < N; ++i){
//         cin >> d >> w;
//         eggs.push_back({d, w});
//     }
//     DFS(0);
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> eggs(9);
int ans = 0;
void DFS(int idx){
    if(idx >= n){
        //깨진 계란들의 개수를 세어줌(음수 값)
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(eggs[i].first <= 0) ++cnt;
        }
        ans = max(ans, cnt);
        return;
    }
    //이미 깨져있는 계란의 경우
    if(eggs[idx].first <= 0) DFS(idx+1);
    else{
        bool check = false;
        for(int i = 0; i < n; ++i){
            //자기자신 or 이미 깨져 있는 경우 다음 값
            if(idx == i || eggs[i].first <= 0) continue;
            
            check = true;

            //계란 충돌
            eggs[i].first -= eggs[idx].second;
            eggs[idx].first -= eggs[i].second;
            
            DFS(idx+1);
            eggs[i].first += eggs[idx].second;
            eggs[idx].first += eggs[i].second;
        }
        //나를 제외한 모든 계란이 깨진 경우
        if(!check) DFS(n);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> eggs[i].first >> eggs[i].second;
    }
    DFS(0);
    cout << ans;
}