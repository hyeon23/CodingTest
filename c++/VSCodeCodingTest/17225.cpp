#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long A, B, N, m;
    long long t;
    char c;
    cin >> A >> B >> N;

    long long n = 1;

    long long curst = 0;

    long long curjt = 0;

    queue<long long> qs;
    queue<long long> qj;

    for(int i = 0; i < N; ++i){
        cin >> t >> c >> m;

        for(int i = 0; i < m; ++i){
            if(c == 'B'){
                if(curst < t){
                    qs.push(t);
                    curst = t + A;
                }
                else{
                    qs.push(curst);
                    curst += A;
                }
            }
            else if(c == 'R'){
                if(curjt < t){
                    qj.push(t);
                    curjt = t + B;
                }
                else{
                    qj.push(curjt);
                    curjt += B;
                }
            }
        }
    }

    vector<long long> slist;
    vector<long long> jlist;

    long long inum = 1;

    while(!qs.empty() || !qj.empty()){

        long long st = __LONG_LONG_MAX__;
        long long jt = __LONG_LONG_MAX__;

        if(!qs.empty()){
            st = qs.front();
        }

        if(!qj.empty()){
            jt = qj.front();
        }

        if(st <= jt){
            slist.push_back(inum);
            qs.pop();
        }
        else{
            jlist.push_back(inum);
            qj.pop();
        }
        ++inum;
    }

    cout << slist.size() << '\n';

    for(int i = 0; i < slist.size(); ++i){
        cout << slist[i] << ' ';
    }
    cout << '\n';

    cout << jlist.size() << '\n';

    for(int i = 0; i < jlist.size(); ++i){
        cout << jlist[i] << ' ';
    }
    cout << '\n';

    return 0;
}