#define HUNGRY 1
#define THIRSTY 2
#define THIRED 4
#define DESEASED 8



int main()
{
    //비트 쉬프트 연산자
    //-비트단위 연산 수행시 진행되는 연산자
    //-쉬프트 <<, >>
    //-비트를 화살표 방향으로 한칸씩 민다.
    //-왼쪽으로 밀면 2^n의 배수로 증가[중요]
    //-오른쪽으로 밀면 2^n로 나눈 몫으로 감소[중요]
    //-초과분은 버림

    unsigned char byte = 1;

    //char = 1byte = 8bit

    byte <<= 1; //00000010[2] << 00000001[1]
    //2가 된다.

    byte <<= 2; //00001000[8] << 00000010[2]
    //8이 된다.
    
    byte >>= 1; //00001000[8] >> 00000100[4]
    //4가 된다.
    
    //비트 반전, 곱, 합, XOR 연산자
    //^ = 비트 반전[Complement]: 0 -> 1, 1 -> 0으로 변환
    //& = 비트 곱: 두 비트 모두 1일 때만, 1
    //| = 비트 합: 한 비트라도 1일 때면, 1
    //^ = 비트 XOR: 1의 개수가 홀수 개면 1

    //게임에서 상태를 표현할 때, 특정 상태 표현을 위해선 겹치지 않는 자리가 필요
    //4byte = 32bit = XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //bit와 전처리기 #define을 적용하면 표현 용이

    int iStatus = HUNGRY;

    return 0;
}