#include <iostream>
using namespace std;

int main(){
//배열 한개 풀이
    // int N, M;

    // cin >> N >> M;

    // int outputArr[N][M] = {};

    // for(int i = 0; i < N; ++i){
    //     for(int j = 0; j < M; ++j){
    //         int tempvalue;

    //         cin >> tempvalue;

    //         outputArr[i][j] = outputArr[i][j] + tempvalue;
    //     }
    // }

    // for(int i = 0; i < N; ++i){
    //     for(int j = 0; j < M; ++j){
    //         int tempvalue;

    //         cin >> tempvalue;

    //         outputArr[i][j] = outputArr[i][j] + tempvalue;
    //     }
    // }

    // for(int i = 0; i < N; ++i){
    //     for(int j = 0; j < M; ++j){
    //         cout << outputArr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

//배열 여러개 풀이
    int a[101][101], b[101][101],n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] + b[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}