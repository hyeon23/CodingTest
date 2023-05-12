#include <iostream>

#include <string>
#include <string.h>

using namespace std;

int main()
{
    string s;
    int count = 0;
    bool flag = true;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
            flag = true;
        else
        {
            if(flag)
                count = count + 1;
            flag = false;
        }
    }
    cout << count;

    //sol2
    char s[1000001];

    //공백을 포함한 입력을 받는 방법: \n이 아닐 때까지 입력받기
	scanf("%[^\n]", &s);

	int cnt = 0;
	if (s[0] != ' ') ++cnt;

	int i = 0;
	while (s[i]) {
		if (s[i] == ' ') ++cnt;
		++i;
	}

	if (s[i - 1] == ' ') --cnt;

	printf("%d\n", cnt);

    return 0;
}