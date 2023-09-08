#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> num_li(N);
        
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            num_li[i] = {x, y};
        }
        
        sort(num_li.begin(), num_li.end());
        
        int idx = N - 1;
        for (int i = 0; i < N - 1; i++) {
            if (num_li[i].first != num_li[i + 1].first) {
                idx = i;
                break;
            }
        }
        
        vector<int> one_unit;
        for (int i = 0; i <= idx; i++) {
            one_unit.push_back(num_li[i].second);
        }
        
        int k = one_unit.size();
        
        for (int i = idx + 1; i < N; i++) {
            if (num_li[i].second != one_unit[i % k]) {
                cout << "NOT BALANCED" << endl;
                break;
            }
            if (i == N - 1) {
                cout << "BALANCED" << endl;
            }
        }
    }
    
    return 0;
}