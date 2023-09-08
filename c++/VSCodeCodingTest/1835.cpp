// #include <deque>
// #include <iostream>
// using namespace std;

// int main(){
//     int N, level = 0;
//     deque<int> carddeck;
//     cin >> N;
//     int* vec = new int[N];
//     for(int i = 0; i < N; ++i)
//         carddeck.push_back(i);//주의: 큐의 push = deque = push_back //push_front가 아님
//     while(!carddeck.empty()){
//         ++level;
//         for(int i = 0; i < level; ++i){
//             carddeck.push_back(carddeck.front());
//             carddeck.pop_front();
//         }
//         vec[carddeck.front()] = level;
//         carddeck.pop_front();
//     }

//     for(int i = 0; i < N; ++i)
//         cout << vec[i] << ' ';
// }

#include <deque>
#include <iostream>
using namespace std;

int main() {
    int N, level = 0;
    cin >> N;
    int* vec = new int[N]; // Fix 1: Allocate memory for N integers

    deque<int> carddeck;
    for (int i = 0; i < N; ++i)
        carddeck.push_back(i);
    
    while (!carddeck.empty()) {
        ++level;
        for (int i = 0; i < level; ++i) {
            carddeck.push_back(carddeck.front());
            carddeck.pop_front();
        }
        vec[carddeck.front()] = level;
        carddeck.pop_front();
    }

    for (int i = 0; i < N; ++i)
        cout << vec[i] << ' ';

    delete[] vec; // Don't forget to deallocate the allocated memory
}