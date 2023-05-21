#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // 메모리도, 시간제한도 맞지만 틀린답이랜다...이유: 고작 10^19까지 밖에 표현할 수 없음
    //  unsigned long long A, B;
    //  cin >> A >> B;
    //  cout << A + B;
    // 완전 다른 방식을 찾아야 함
    string A, B, S;
    cin >> A >> B;
    int carry = 0;

    int smallLen;

    if (A.length() < B.length())
    {
        smallLen = A.length();
        S = B;
    }
    else if (A.length() == B.length())
    {
        smallLen = A.length();
        S = A;
    }
    else
    {
        smallLen = B.length();
        S = A;
    }

    for (int i = 0; i < smallLen + 1; ++i)
    {
        if (A.length() < B.length())
        {
            if (i == smallLen)
            {
                if (carry != 0)
                
                {
                    S[S.length() - 1 - i] = (char)((int)(B[B.length() - 1 - i] - '0') + carry);
                    cout << "cS"  << carry << S;
                }
                else
                {
                    cout << "S" << S;
                }
            }
            else
            {
                S[S.length() - 1 - i] = (char)((int)((A[A.length() - 1 - i] - '0') + (B[B.length() - 1 - i] - '0') + carry) % 10);
                carry = (int)((A[A.length() - 1 - i] - '0') + (B[B.length() - 1 - i] - '0') + carry) / 10;
            }
        }
        else if (A.length() == B.length())
        {
            if (i == smallLen)
            {
                if (carry != 0)
                {
                    S[S.length() - 1 - i] = ((A[A.length() - 1 - i] - '0') + (B[B.length() - 1 - i] - '0') + carry) % 10;
                    cout << carry << S;
                }
                else
                {
                    cout << S;
                }
            }
            else
            {
                S[S.length() - 1 - i] = ((A[A.length() - 1 - i] - '0') + (B[B.length() - 1 - i] - '0') + carry) % 10;
                carry = (A[A.length() - 1 - i] - '0' + B[B.length() - 1 - i] - '0' + carry) / 10;
            }
        }
        else
        {
            if (i == smallLen)
            {
                if (carry != 0)
                {
                    S[S.length() - 1 - i] = ((A[A.length() - 1 - i] - '0') + carry);
                    cout << carry << S;
                }
                else
                {
                    cout << S;
                }
            }
            else
            {
                S[S.length() - 1 - i] = ((A[A.length() - 1 - i] - '0') + (B[B.length() - 1 - i] - '0') + carry) % 10;
                carry = (A[A.length() - 1 - i] - '0' + B[B.length() - 1 - i] - '0' + carry) / 10;
            }
        }
        cout << carry << endl;
    }

    return 0;
}