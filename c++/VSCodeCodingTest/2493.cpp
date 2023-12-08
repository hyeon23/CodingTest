// #include <iostream>
// #include <vector>
// #include <deque>
// using namespace std;
// struct st
// {
//     int x;
//     int y;
// };
// int main()
// {
//     int N, tmp;
//     deque<st> stk;
//     cin >> N;
//     vector<int> vec(N + 1, 0);
//     for (int i = 1; i <= N; ++i)
//     {
//         cin >> tmp;
//         st tower = {i, tmp};
//         // 현재 탑보다 작은 높이의 탑들을 스택에서 제거
//         while (!stk.empty() && stk.back().y < tmp)
//         {
//             stk.pop_back();
//         }
//         if (!stk.empty())
//         {
//             vec[i] = stk.back().x; // 남은 탑 중에서 신호를 받을 수 있는 경우
//         }
//         stk.push_back(tower);
//     }
//     for (int i = 1; i <= N; ++i)
//     {
//         cout << vec[i] << ' ';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, height;
    cin >> N;
    stack<pair<int, int>> stk;
    stk.push({100000001, 0});
    for(int i = 1; i <= N; ++i){
        cin >> height;
        while(!stk.empty() && stk.top().first < height) stk.pop();
        cout << stk.top().second << ' ';
        stk.push({height, i});
    }
    return 0;
}