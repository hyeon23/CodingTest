#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<queue<int>> Sun(2); // 선착장 0: 왼쪽, 1: 오른쪽
    queue<int> boat;
    int M, t, N, time, curpos = 0; // 배 최대 M명, 강의 길이(강건너는 시간), 횟수

    string dir;
    cin >> M >> t >> N;

    for (int i = 0; i < N; ++i) {
        cin >> time >> dir;
        if (dir == "left")
            Sun[0].push(time);
        else
            Sun[1].push(time);
    }

    int curtime = 0;

    while (!Sun[0].empty() || !Sun[1].empty()) {
        // Unload passengers from the boat
        while (!boat.empty()) {
            boat.pop();
            cout << curtime << '\n';
        }

        // Load passengers onto the boat if possible
        int other = (curpos == 0) ? 1 : 0;
        while (!Sun[curpos].empty() && Sun[curpos].front() <= curtime && boat.size() < M) {
            boat.push(Sun[curpos].front());
            Sun[curpos].pop();
        }

        //25 40 --- 10

        // Move to the other side if no more passengers are waiting
        if (boat.empty() && Sun[other].empty()) {
            curtime = max(curtime, Sun[curpos].front());
        } else {
            curtime += t;
            curpos = other;
        }
    }
    cout << curtime << '\n';

    return 0;
}