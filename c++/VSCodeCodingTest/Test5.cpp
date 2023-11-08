#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'three_numbers' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER t
 *  2. INTEGER_ARRAY d
 */

long three_numbers(int t, vector<int> d) {
    long ans = 0;
    int n = d.size();

    sort(d.begin(), d.end()); // 숫자 카드 리스트를 정렬

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int sum = d[i] + d[j];
            int upper_bound = t - sum;
            auto it = upper_bound(d.begin() + j + 1, d.end(), upper_bound);
            int count = distance(d.begin() + j + 1, it);
            ans += count;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    string d_count_temp;
    getline(cin, d_count_temp);

    int d_count = stoi(ltrim(rtrim(d_count_temp)));

    vector<int> d(d_count);

    for (int i = 0; i < d_count; i++) {
        string d_item_temp;
        getline(cin, d_item_temp);

        int d_item = stoi(ltrim(rtrim(d_item_temp)));

        d[i] = d_item;
    }

    long result = three_numbers(t, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
