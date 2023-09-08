// #include <queue>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     // 우선순위 큐
//     int T, N, M, x, cnt = 0;

//     cin >> T;

//     for (int i = 0; i < T; ++i)
//     {
//         queue<pair<int, int>> queue; //{i, x}
//         vector<int> vec;
//         cnt = 0;
//         cin >> N >> M;

//         for (int j = 0; j < N; ++j)
//         {
//             cin >> x;
//             queue.push({j, x});
//             vec.push_back(x);
//         }

//         sort(vec.begin(), vec.end(), greater<int>());

//         while (true)
//         {
//             if (queue.front().second == vec[0])
//             {
//                 cnt++;

//                 if (queue.front().first == M)
//                 {
//                     cout << cnt << '\n';
//                     break;
//                 }

//                 queue.pop();
//                 vec.erase(vec.begin());
//             }
//             else
//             {
//                 queue.push(queue.front());
//                 queue.pop();
//             }
//         }
//     }
// }

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int count = 0;
    int test_case;
    cin >> test_case;
    int n, m, ipt;//문서의 개수, 궁금한 문서 위치, 중요도
    for(int i = 0; i < test_case; ++i){
        count = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;//우선순위 큐
        for(int j = 0; j < n; ++j){
            cin >> ipt;
            q.push({j, ipt});
            pq.push(ipt);
        }
        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){
                pq.pop();
                ++count;
                if(index == m){
                    cout << count << '\n';
                    break;
                }
            }
            else q.push({index, value});
        }
    }
}