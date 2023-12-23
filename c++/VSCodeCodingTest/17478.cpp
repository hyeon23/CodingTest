#include <bits/stdc++.h>
using namespace std;

int N;

void recursion1(int cur){
    string str(4*cur, '_');
    if(cur == N) {
        cout << str;
        cout << "\"����Լ��� ������?\"\n";
        cout << str;
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        return;
    }
    else{
        cout << str;
        cout << "\"����Լ��� ������?\"\n";
        cout << str;
        cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        cout << str;
        cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        cout << str;
        cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        recursion1(cur+1);
    }
}

void recursion2(int cur){
    if(cur == 0) return;

    string str(4*(cur-1), '_');
    cout << str;
    cout << "��� �亯�Ͽ���.\n";
    recursion2(cur-1);
}

int main(){
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recursion1(0);
    recursion2(N+1);
    return 0;
}