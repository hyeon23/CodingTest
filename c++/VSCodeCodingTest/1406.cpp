// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// int main()
// {
//     int M;
//     string s = "";
//     stack<char> left;//left는 커서 기준 왼쪽 원소
//     stack<char> right;//right는 커서 기준 오른쪽 원소

//     cin >> s;

//     for (int i = 0; i < (int)s.size(); i++)
//         left.push(s[i]);

//     cin >> M;

//     for (int i = 0; i < M; i++)
//     {
//         char cmd, c;
//         cin >> cmd;

//         if (cmd == 'L')
//         {
//             if (!left.empty())
//             {
//                 right.push(left.top());
//                 left.pop();
//             }
//         }
//         else if (cmd == 'D')
//         {
//             if (!right.empty())
//             {
//                 left.push(right.top());
//                 right.pop();
//             }
//         }
//         else if (cmd == 'B')
//         {
//             if (!left.empty())
//                 left.pop();
//         }
//         else if (cmd == 'P')
//         {
//             cin >> c;
//             left.push(c);
//         }
//     }

//     // left에 있는 원소들 모두 right로 이동!
//     while (!left.empty())
//     {
//         right.push(left.top());
//         left.pop();
//     }

//     // right에 있는 원소 출력
//     while (!right.empty())
//     {
//         cout << right.top();
//         right.pop();
//     }
// }

#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int M;
    string s = "";
    string ans = "";

    cin >> s;
    // 연결리스트에 원소 할당
    list<char> li(s.begin(), s.end());

    // 커서위치를 입력된 문자 제일 끝에 위치
    auto cursor = li.end();
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (cursor != li.begin())
                cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor != li.end())
                cursor++;
        }
        else if (cmd == 'B')
        {
            if (cursor != li.begin()) // 맨 왼쪽이 아니라면
            {
                cursor--;
                cursor = li.erase(cursor); // 삭제
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            li.insert(cursor, c); // 문자 c 삽입
        }
    }

    // 연결리스트 출력
    for (cursor = li.begin(); cursor != li.end(); cursor++)
        cout << *cursor;
}