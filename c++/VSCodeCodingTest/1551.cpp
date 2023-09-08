#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    cin.ignore();
    string tmp;
    vector<int> vec;
    while(N--){
        getline(cin, tmp, ',');
        vec.push_back(stoi(tmp));
    }
        
    for(int i = 0; i < N - 1; ++i)
        vec[i] = vec[i + 1] - vec[i];
    for(int i = 0; i < vec.size() - K; ++i)
        cout << vec[i] << ' ';
}