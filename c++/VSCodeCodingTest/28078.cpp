#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque<char> q;
    int Q;
    string cmd1;
    char cmd2;
    cin >> Q;
    int curbcnt = 0, curwcnt = 0;

    int qstate = 0;//0, 1, 2, 3
    
    for(int i = 0; i < Q; ++i){
        cin >> cmd1;
        if(cmd1 == "push"){
            cin >> cmd2;
            if(cmd2 == 'b'){
                if(qstate == 0 || qstate == 2){
                    ++curbcnt;
                    q.push_front('b');
                }
                else if(qstate == 1){
                    if(!q.empty()) { 
                        q.push_front('b');
                        ++curbcnt;
                    }
                }
            }
            else if(cmd2 == 'w'){
                q.push_front('w');
                ++curwcnt;
            }
        }
        //B W
        else if(cmd1 == "rotate"){
            cin >> cmd2;
            if(cmd2 == 'l'){//반시계 회전
                if(qstate == 0) qstate = 3;
                else --qstate;
            }
            else if(cmd2 == 'r'){//시계 회전
                if(qstate == 3) qstate = 0;
                else ++qstate;
            }

            if(qstate == 1){//상 뒤 하 앞: 아래에서 부터 판자를 만날때까지 pop
                while(!q.empty()){
                    if(q.back() == 'w') break;
                    else {
                        q.pop_back();
                        --curbcnt;
                    }
                }
            }
            else if(qstate == 3){
                while(!q.empty()){
                    if(q.front() == 'w') break;
                    else {
                        q.pop_front();
                        --curbcnt;
                    }
                }
            }
        }
        else if(cmd1 == "count"){
            cin >> cmd2;
            if(cmd2 == 'b')
                cout << curbcnt << '\n';
            else if(cmd2 == 'w')
                cout << curwcnt << '\n';
        }
        else if(cmd1 == "pop"){
            if(!q.empty()) {
                --curbcnt;
                q.pop_back();
                
                if(q.back() == 'w') {
                    if(!q.empty()){
                        if(qstate == 1){
                            while(!q.empty()){
                                if(q.back() == 'w') break;
                                else {
                                    q.pop_front();
                                    --curbcnt;
                                }
                            }
                        }
                        else if(qstate == 3){
                            while(!q.empty()){
                                if(q.front() == 'w') break;
                                else {
                                    q.pop_front();
                                    --curbcnt;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}