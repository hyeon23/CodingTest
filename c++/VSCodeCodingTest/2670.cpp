#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<double> dvec(N);

    double MAX = INT_MIN;

    for(int i = 0; i < N; ++i){
        cin >> dvec[i];

        MAX = max(MAX, dvec[i]);
    }

    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            double tmp = accumulate(dvec.begin(), dvec.end(), 0, multiplies<double>());

            cout << tmp << '\n';

            MAX = max(MAX, tmp);
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << MAX;

    return 0;
}