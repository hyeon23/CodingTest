#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Get;

void MakeGet(){
    cin >> N;
    Get.push_back(0);
    for(int i = 1; i <= N; ++i){
        int X;
        cin >> X;
        Get.push_back(X); //각 지뢰의 폭발력을 넣어준다.
    }
    Get.push_back(0); //양 끝에 0을 넣어주는 방법
}

void Solve(){
    for(int i = 1; i <= N; ++i){
        if(Get[i] >= Get[i-1] && Get[i] >= Get[i+1]) cout << i << '\n';
    }
}

int main(){
    MakeGet();
    Solve();
}