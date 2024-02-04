#include <bits/stdc++.h>
using namespace std;
int k;
string X, Y, Z;
map<string, int> m;
void DFS(string str, int depth){
    if(depth == k){

    }
    DFS(str, depth+1);

}
int main(){
    cin >> X >> Y >> Z >> k;
    DFS(X, 0);
    DFS(Y, 0);
    DFS(Z, 0);
    return 0;
}