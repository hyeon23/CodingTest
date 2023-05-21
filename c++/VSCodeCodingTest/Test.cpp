#include <iostream>

using namespace std;

int main(){
    int ary1[2][4];
    ary1[0][0] = 3;

    //중괄호 사용시, 0으로 초기화
    int arr2[2][4]{};

    cout << "arr2 출력\n";
    for(int row = 0; row < 2; ++row){
        for(int col = 0; col < 4; ++col){
            cout << arr2[row][col] << " ";
        }
        cout << endl;
    }

    int ary3[2][4] = {
        {1, 2, 3, 4,},
        {10, 20, 30, 40,},
    };

    int ary4[2][4] = {1,2,3,4,10,20,30,40};

    int ary5[2][4] = {
        {1},    //나머지 3열은 0으로 초기화 {1, 0, 0, 0}과 동일
        {2, 3}  //나머지 2열은 0으로 초기화 {2, 3, 0, 0}과 동일
    };

    int ary[2][4]{};
    int* ptr = &ary[0][0];
    cout << "메모리 주소 위치 \t\t offset" << endl;
    for(int row = 0; row < 2; ++row){
        for(int col = 0; col < 4; ++col){
            printf("ary[%d][%d]: %p\t", row, col, &ary[row][col]);
            if(row | col)
                printf("이전 원소와 차이 %d", (size_t)&ary[row][col] - (size_t)ptr);
                ptr = &ary[row][col];
                cout << endl;
        }
    }

    int arr[][4] = {1,2,3,4,5,6,7,8};
    
    for(int row = 0; row < sizeof(arr) / sizeof(arr[row]); ++row){
        for(int col = 0; col < sizeof(arr[row]) / sizeof(int); ++col){
            cout << arr[row][col] << " ";
        }
    }

    return 0;
}