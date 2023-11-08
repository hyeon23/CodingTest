#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'GetMaxScore' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

int GetMaxScore(const vector<int>& scores) {
    int n = scores.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = scores[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++) {
        dp[i][0] = scores[i] + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string scores_count_temp;
    getline(cin, scores_count_temp);

    int scores_count = stoi(ltrim(rtrim(scores_count_temp)));

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        string scores_item_temp;
        getline(cin, scores_item_temp);

        int scores_item = stoi(ltrim(rtrim(scores_item_temp)));

        scores[i] = scores_item;
    }

    int result = GetMaxScore(scores);

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
