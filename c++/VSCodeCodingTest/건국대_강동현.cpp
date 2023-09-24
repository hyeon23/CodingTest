#include <map>
#include <string>
#include <vector>

using namespace std;
 
vector<int> solution(string msg)
{
    int num = 0;
    map<string, int> dict;

    vector<int> answer;

    for (char c = 'A'; c <= 'Z'; c++)
    {
        string str = "";
		str += c;
        dict[str] = ++num;
    }

    string cur = "";

    for (int i = 0; i < msg.length(); i++)
    {
        cur += msg[i];
        if (dict[cur] == 0)
        {
            dict[cur] = ++num;
            answer.push_back(dict[cur.substr(0, cur.length() - 1)]);//현재 입력값 필요
            cur = "";
            i--;
        }
    }
    answer.push_back(dict[cur]);
    return answer;
}