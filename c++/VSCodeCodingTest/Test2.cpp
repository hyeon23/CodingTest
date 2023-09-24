#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator() (pair<int, int> A, pair<int, int> B){
        if(A.second == B.second)
            return A.first > B.first;
        return A.second < B.second;
    }
};

struct cmpmap{
    bool operator() (int A, int B){
        return A < B;
    }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    //, vector<pair<int, int>, cmp>

    pq.push({1, 2});
    pq.push({2, 3});
    pq.push({3, 4});
    pq.push({4, 5});
    pq.push({1, 5});
    pq.push({5, 5});
    pq.push({5, 6});

    while(!pq.empty()){
        pair<int, int> fr = pq.top();
        cout << fr.first << ' ' << fr.second << '\n';
        pq.pop();
    }

    cout << '\n';

    map<int, int, cmpmap> m;

    m[1] = 100000;
    m[2] = 2;
    m[3] = 500;
    m[4] = 4;
    m[5] = 300;
    m[6] = 5;
    m[7] = 100;

    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}