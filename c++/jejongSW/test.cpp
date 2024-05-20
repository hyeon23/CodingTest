#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), ::toupper);
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    return myString.find(pat) != string::npos;
}

#include <string>
#include <vector>
using namespace std;
string solution(string my_string, string overwrite_string, int s)
{
    string answer = "";
    answer = my_string.replace(s, overwrite_string.size(), overwrite_string);
    return answer;
}

#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<int>> lines){
    int answer = 0;
    vector<int> vec(200, 0);
    for(int i = 0; i < lines.size(); ++i){
        for(int j = lines[i][0]; j < lines[i][1]; ++j){
            vec[j+100]++;
        }
    }
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] >= 2) ++answer;
    }
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int solution(vector<vector<int>> lines){
    int answer = 0;
    map<int, int> m;
    for(const auto& l : lines){
        for(int i = l[0]; i <= l[1]; ++i){
            m[i]++;
        }
        for(const auto& p : m)
        {
            if(p.second >= 2){
                ++answer;
            }
        }
        return answer - 1;
    }
}
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int solution(vector<int> array){
    int answer = 0;
    int maxV = 0;
    unordered_map<int, int> um;
    for(const auto v : array) um[v]++;
    for(const auto& v : um){
        if(v.second > maxV){
            maxV = v.second;
            answer = v.first;
        }
        else if(v.second == maxV) answer -1;
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> array){
    sort(array.begin(), array.end());
    vector<int> vec(1001, 0);
    for(int i = 0; i < array.size(); ++i) vec[array[i]]++;
    auto max = max_element(vec.begin(), vec.end());
    int cnt = 0; int value = 0;
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] == *max){
            ++cnt;
            value = i;
        }
    }
    if(cnt == 1) return value;
    else return -1;
}

#include <string>
#include <vector>
using namespace std;
int gcd(int x, int y){
    if(x % y == 0) return y;
    else return gcd(y, x % y);
}
int solution(int balls, int share){
    int answer1 = balls;
    int answer2 = share;
    int resultc = 1, resultm = 1;
    for(int i = 0; i < share; ++i){
        resultc = resultc * answer1--;
        resultm = resultm * answer2--;

        int GCD = gcd(resultc, resultm);
        resultc = resultc / GCD;
        resultm = resultm / GCD;
    }
    return resultc / resultm;
}

#include <string>
#include <vector>
using namespace std;
int combi(int n, int r){
    if(r == 0) return 1;
    if(n == 1) return 1;
    if(r >= n) return 1;
    return combi(n-1, r) + combi(n-1, r-1);
}
int solution(int balls, int share){
    int answer = 0;
    answer = combi(balls, share);
    return answer;
}
#include <string>
#include <vector>
vector<int> solution(vector<vector<int>> score){
    vector<int> answer;
    for(auto& s : score){
        s.emplace_back(s[0] + s[1]);
    }
    for(const auto v : score){
        int count = 0;
        for(const auto t : score){
            count += (t[2] > v[2]);
        }
        answer.emplace_back(count + 1);
    }
    return answer;
}

struct A{
    int a;
    int b;
    public void A();
};
