#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    //일반/패국/승국
    int N, M;
    cin >> N >> M;
    cin.ignore();
    map<string, int> nationals;
    string str;
    while(N--){
        getline(cin, str);
        nationals[str.substr(11)] = 0;
    }
    while(M--){
        getline(cin, str);
        stringstream ss(str);
        string tmp;
        int i = 0;
        string A;
        string B;
        int mode;
        while(getline(ss, tmp, ',')){
            if(i % 3 == 0)
                A = tmp.substr(11);
            else if(i % 3 == 1)
                B = tmp.substr(11);
            else if(i % 3 == 2)
                mode = stoi(tmp);
            ++i;
        }

        if(mode == 1){
            if(nationals[A] == -1){
                if(nationals[B] == 1 || nationals[B] == 0){
                    nationals[A] = 1;
                    nationals[B] = -1;
                }
                else if(nationals[B] == -1){
                    nationals[A] = -1;
                }
            }
            else if(nationals[A] == 0){
                nationals[A] = 1;
                nationals[B] = -1;
            }
            else if(nationals[A] == 1)
                nationals[B] = -1;
        }
        else if(mode == 2){
            if(nationals[B] == -1){
                if(nationals[A] == 1 || nationals[A] == 0){
                    nationals[B] = 1;
                    nationals[A] = -1;
                }
                else if(nationals[A] == -1){
                    nationals[B] = -1;
                }
            }
            else if(nationals[B] == 0){
                nationals[B] = 1;
                nationals[A] = -1;
            }
            else if(nationals[B] == 1)
                nationals[A] = -1;
        }
    }
    int count = 0;
    for(auto i : nationals)
        if(i.second == 1 || i.second == 0)
            ++count;
    cout << count << '\n';
    for(auto i : nationals)
        if(i.second == 1 || i.second == 0)
            cout << "Kingdom of " << i.first << '\n';
    return 0;
}