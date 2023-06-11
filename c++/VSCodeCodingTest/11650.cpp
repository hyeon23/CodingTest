// #include <iostream>
// #include <stdio.h>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct position
// {
//     int x, y;
// };

// bool compare(position now, position last)
// {
//     if (now.x > last.x)
//         return false;

//     if (now.x == last.x && now.y > last.y)
//         return false;

//     return true;
// }

// int main()
// {
//     // sol1: <pair> vector의 sort -> x 기준 정렬 후, y 기준 정렬
//     //  int N;
//     //  cin >> N;
//     //  int x, y;
//     //  vector<pair<int, int>> vec;

//     // for(int i = 0; i < N; ++i){
//     //     cin >> x >> y;
//     //     vec.push_back(make_pair(x, y));
//     //     //vec.push_back({x, y});
//     // }
//     // sort(vec.begin(), vec.end());
//     // for(int i = 0; i < N; ++i){
//     //     cout << vec[i].first << " " << vec[i].second << '\n';
//     // }

//     // sol2: <vector> vector의 sort -> x 기준 정렬 후, y 기준 정렬
//     //  int N;
//     //  cin >> N;
//     //  vector<vector<int>> arr(N, vector<int>(2, 0));
//     //  for(int i = 0; i < N; ++i){
//     //      cin >> arr[i][0] >> arr[i][1];
//     //  }
//     //  sort(arr.begin(), arr.end());
//     //  for(int i = 0; i < arr.size(); ++i){
//     //      cout << arr[i][0] << " " << arr[i][1] << '\n';
//     //  }

//     // sol3: 직접 짜기
//     int N;
//     scanf("%d", &N);
//     struct position arr[100001];

//     for (int i = 0; i < N; ++i)
//     {
//         scanf("%d %d", &arr[i].x, &arr[i].y);
//     }

//     // iterator == 주소
//     sort(arr, arr + N, compare);

//     for (int i = 0; i < N; ++i)
//         printf("%d %d\n", arr[i].x, arr[i].y);
// }