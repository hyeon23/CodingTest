#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    int n;
    cin >> T;

    vector<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(4);

    for (int i = 3; i < 11; i++)
    {
        list.push_back(list[i - 1] + list[i - 2] + list[i - 3]);
    }

    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << list[n - 1] << endl;
    }
}