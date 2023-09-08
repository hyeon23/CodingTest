//1. DFS 해결법
#include <iostream>

using namespace std;

int a[12], op[4];
int n, ansMax = -2147000000, ansMin = 2147000000;

void DFS(int idx, int sum){
    if(idx == n - 1){
        ansMax = max(ansMax, sum);
        ansMin = min(ansMin, sum);
    }
    else{
        if(op[0] > 0){//덧셈 연산
            op[0]--;
            DFS(idx + 1, sum + a[idx + 1]);
            op[0]++;
        }

        if(op[1] > 0){//뺄셈 연산
            op[1]--;
            DFS(idx + 1, sum - a[idx + 1]);
            op[1]++;
        }

        if(op[2] > 0){//곱셈 연산
            op[2]--;
            DFS(idx + 1, sum * a[idx + 1]);
            op[2]++;
        }

        if(op[3] > 0){//나눗셈 연산
            op[3]--;
            DFS(idx + 1, sum / a[idx + 1]);
            op[3]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < 4; ++i)
        cin >> op[i];

    DFS(0, a[0]);//a의 인덱스, 연산 수행 후 합

    cout << ansMax << '\n' << ansMin;
}

// //2. Next Permutation 해결법
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, ansMax = -2147000000, ansMin = 2147000000;
//     cin >> n;
//     int a[n];
//     vector<int> op;

//     for(int i = 0; i < n; ++i)
//         cin >> a[i];

//     for(int i = 0; i < 4; ++i){
//         int tmp;
//         cin >> tmp;
//         while(tmp--)
//             op.push_back(i);
//     }

//     sort(op.begin(), op.end());

//     do{
//         int idx= 0;
//         int sum = a[0];
//         //연산자의 수는 항상 숫자의 수보다 1 적다.
//         for(int i = 0; i < n - 1; ++i){
//             if(op[i] == 0)
//                 sum += a[++idx];
//             else if(op[i] == 1)
//                 sum -= a[++idx];
//             else if(op[i] == 2)
//                 sum *= a[++idx];
//             else if(op[i] == 3)
//                 sum /= a[++idx];
//         }

//         ansMax = max(ansMax, sum);
//         ansMin = min(ansMin, sum);
//     } while(next_permutation(op.begin(), op.end()));

//     cout << ansMax << '\n' << ansMin;
// }