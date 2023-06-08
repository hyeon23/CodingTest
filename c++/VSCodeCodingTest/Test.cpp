#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec = {1,3,5,5,7,8,8,10,10,11,13};

    sort(vec.begin(), vec.end());

    cout << "5의 갯수 : " << upper_bound(vec.begin(), vec.end(), 5) - lower_bound(vec.begin(), vec.end(), 5);
}