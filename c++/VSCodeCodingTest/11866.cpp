// #include <queue>
// #include <vector>
// #include <iostream>
// using namespace std;
// /*1 ~ N K*/
// int main()
// {
//     int N, K;
//     int curIndex = 2;

//     cin >> N >> K;

//     queue<int> q;
//     vector<int> vec;

//     for (int i = 1; i <= N; ++i)
//     {
//         q.push(i);
//     }

//     for (int i = 0; i < N; ++i)
//     {
//         for (int i = 0; i < K; ++i)
//         {
//             if (i == K - 1)
//             {
//                 vec.push_back(q.front());
//                 q.pop();
//             }
//             else
//             {
//                 q.push(q.front());
//                 q.pop();
//             }
//         }
//     }

//     cout << "<";
//     for (int i = 0; i < vec.size(); ++i)
//     {
//         if (i == vec.size() - 1)
//         {
//             cout << vec[i];
//         }
//         else
//             cout << vec[i] << ", ";
//     }
//     cout << ">";
// }

#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) q.push(i);
    cout << "<";

    while(q.size() != 0){
        for(int i = 1; i < K; ++i){
            q.push(q.front());//i번재 카드를 맨 뒤로
            q.pop();
        }
        cout << q.front();
        if(q.size() != 1) cout << ",";
        q.pop();
    }
    cout << ">";
}