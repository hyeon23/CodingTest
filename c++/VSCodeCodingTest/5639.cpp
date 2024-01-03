#include <bits/stdc++.h>
using namespace std;
int tree[10000];
void postOrder(int start, int end){
    if(start >= end) return;
    if(start == end - 1){
        cout << tree[start] << '\n';
        return;
    }
    int idx = start + 1;
    while(idx < end){
        if(tree[start] < tree[idx]) break;
        idx++;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    int inputIdx = 0;
    while(cin >> num){
        tree[inputIdx++] = num;
    }
    postOrder(0, inputIdx);    
    return 0;
}