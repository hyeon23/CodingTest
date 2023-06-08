#include <iostream>

using namespace std;

//sol1) 반복문의 범위를 유추
//(n - 2)(n - 1)n
//n = 3 -> 1 => 해당 식에선 6
//n = 4 -> 4 => 해당 식에선 24
//n = 5 -> 10 => 해당 식에선 60
//=>해당 식을 6으로 나눈 것이 답

//sol2) 


// MenOfPassion(A[], n) {
//     sum <- 0;
//     for i <- 1 to n - 2
//         for j <- i + 1 to n - 1
//             for k <- j + 1 to n
//                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
//     return sum;
// }

int main(){
    long long N;
    cin >> N;

    cout << (N - 2) * (N - 1) * N / 6 << endl;
    cout << 3;
}