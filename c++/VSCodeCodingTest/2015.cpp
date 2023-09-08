#include <iostream>
#include <map>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
long long n, k, cnt, lis[202020], acc[202020];
map<long long, long long> m;
int main() {
    fastio();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> lis[i];
    for (int i = 1; i <= n; i++) acc[i] = acc[i - 1] + lis[i];
    for (int i = 1; i <= n; i++) {
        if (acc[i] == k) cnt++;
        if (m.find(acc[i] - k) != m.end()) cnt += m[acc[i] - k];
        if (m.find(acc[i]) != m.end()) m[acc[i]]++;
        else m.insert({acc[i], 1});
    }
    cout << cnt;
    return 0;
}