#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) 
            return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    priority_queue<int, vector<int>, cmp2> pq;
    int N, tmp;
    cin >> N;
    while(N--){
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(tmp);
        }
    }
}
