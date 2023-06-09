#include <iostream>
using namespace std;

int main()
{
    // sol1: 시간복잡도 에러[반복문이 아닌 if문으로 풀어야 함]
    //  int A, B, V;
    //  int day = 1;
    //  cin >> A >> B >> V;
    //  while(true){
    //      V -= A;
    //      if(V > 0){
    //          V += B;
    //          day++;
    //      }
    //      else{
    //          break;
    //      }
    //  }
    //  cout << day;
    //  return 0;

    int A, B, V;
    int day = 1;
    cin >> A >> B >> V;

    day += (V - A) / (A - B);

    if((V - A) % (A - B) != 0)
        day+= 1;
        
    cout << day;
}