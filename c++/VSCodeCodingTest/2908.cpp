#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A, B;

    cin >> A >> B;

    int answer;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    answer = max(stoi(A), stoi(B));

    cout << answer;

    return 0;
}