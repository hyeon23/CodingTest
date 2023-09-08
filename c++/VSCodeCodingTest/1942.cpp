#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 3; ++i){
        string start, end;
        cin >> start >> end;
        
        vector<int> startt = {stoi(start.substr(0, 2)), stoi(start.substr(3, 2)), stoi(start.substr(6, 2))};
        vector<int> endt = {stoi(end.substr(0, 2)), stoi(end.substr(3, 2)), stoi(end.substr(6, 2))};

        int count = 0;

        while(startt[0] != endt[0] && startt[1] != endt[1] && startt[2] != endt[2]){
            startt[2] += 1;

            if(startt[2] >= 60){
                startt[2] -= 60;
                startt[1] += 1;
            }

            if(startt[1] >= 60){
                startt[1] -= 60;
                startt[0] += 1;
            }

            if(startt[0] >= 60){
                startt[0] -= 60;
            }

            string tmp = to_string(startt[0]) + to_string(startt[1]) + to_string(startt[2]);
            
            int sum = 0;

            cout << tmp << '\n';

            for(int i = 0; i < tmp.size(); ++i)
                sum += tmp[i] - '0';

            if(sum % 3 == 0) ++count;
        }
        cout << count << '\n';
    }
}