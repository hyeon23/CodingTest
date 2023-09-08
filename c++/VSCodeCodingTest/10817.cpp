#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C;
    vector<int> vec;
    cin >> A >> B >> C;
    vec.push_back(A);
    vec.push_back(B);
    vec.push_back(C);
    sort(vec.begin(), vec.end());
    cout << vec[1];
}