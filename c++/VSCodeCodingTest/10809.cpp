#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    // sol0
    //char 배열을 쓸 땐 문자열이 입력하고, 마지막에 항상 NUL 문자 '\0'이 들어간다.
    //해당 내용을 까먹고 배열의 길이 제한이 100이라 100으로 하면 문제가 생길 수 있다는 소리
    //참고로 아스키 코드에 해당하는 '0' = 47이고, 이는 int로 char를 사용할 때 사용한다.
    char S[101];
    int alpha[26];
    cin >> S;

    for (int i = 0; i < 26; ++i)
    {
        alpha[i] = -1;
    }

    for (int i = 0; i < strlen(S); ++i)
    {
        if (alpha[(int)S[i] - 97] < 0)
            alpha[(int)S[i] - 97] = i;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << alpha[i] << " ";
    }

    // sol1
    string S2;
    int alpha[26];
    cin >> S2;

    for (int i = 0; i < 26; ++i)
    {
        alpha[i] = -1;
    }

    for (int i = 0; i < S2.length(); ++i)
    {
        if (alpha[(int)S[i] - 97] < 0)
            alpha[(int)S[i] - 97] = i;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << alpha[i] << " ";
    }

    // sol2
    string s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    for (int i = 0; i < alphabet.length(); i++)
        cout << (int)s.find(alphabet[i]) << " ";
    return 0;
}