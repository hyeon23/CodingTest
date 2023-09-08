#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    unordered_map<char, char> m;
    int n;
    cin >> s >> n;
    for (char c = 'A'; c <= 'z'; c++)
        m[c] = c;
    for (int i = 0; i < n; i++)
    {
        char p, q;
        int choice;

        cin >> choice;

        if (choice == 1)
        {
            cin >> p >> q;

            for (auto temp : m)
                if (temp.second == p)
                    m[temp.first] = q;
        }
        else
        {
            for (char temp : s) cout << m[temp];
            cout << '\n';
        }
    }

    return 0;
}
