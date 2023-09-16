//에르나 노바: 재사용 100 / 90초 면역
//오리진 스킬: 재사용 360 / 90초 면역

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> A, pair<string, int> B){
    return A.second < B.second;
}

int main(){
    int N, M, tmp;
    cin >> N >> M;

    vector<pair<string, int>> A;

    for(int i = 0; i < N; ++i){
        cin >> tmp;
        A.push_back({"A", tmp});
    }

    for(int i = 0; i < M; ++i){
        cin >> tmp;
        A.push_back({"B", tmp});
    }
    sort(A.begin(), A.end(), cmp);
    int curtime = 0;
    int Acool = 0;
    int Bcool = 0;
    int Acnt = 0;
    int Bcnt = 0;
    for(int i = 0; i < A.size(); ++i){
        //쿨타임 체크
        if(A[i].second > curtime){//현재 시간보다 스킬을 늦게 썼다.
            if(A[i].first == "A"){
                Bcool = (Bcool - (A[i].second - curtime)) <= 0 ? 0 : Bcool - (A[i].second - curtime);
                Acool = (Acool - (A[i].second - curtime)) <= 0 ? 0 : Acool - (A[i].second - curtime);
                if(Acool == 0){
                    Acool += 100;
                    Acnt++;
                }
            }
            else if(A[i].first == "B"){
                Bcool = (Bcool - (A[i].second - curtime)) <= 0 ? 0 : Bcool - (A[i].second - curtime);
                Acool = (Acool - (A[i].second - curtime)) <= 0 ? 0 : Acool - (A[i].second - curtime);
                if(Bcool == 0){
                    Bcool += 100;
                    Bcnt++;
                }
            }
        }
        else if(A[i].second == curtime){//현재 시간과 스킬을 사용한 시간이 같다.
            if(A[i].first == "A"){
                if(Acool == 0){
                    Acool += 100;
                    Acnt++;
                }
            }
            else if(A[i].first == "B"){
                if(Bcool == 0){
                    Bcool += 100;
                    Bcnt++;
                }
            }
        }
        curtime = A[i].second;
    }
    cout << Acnt << ' ' << Bcnt;
}
