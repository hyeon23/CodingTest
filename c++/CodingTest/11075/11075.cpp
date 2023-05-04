#include <stdio.h>

typedef struct _tagMyType {
	//너무 방대한 구조체
	int a;
	int b;
	//...
	int zzz;
}MyType;

void Output(const int* pI) {
	int i = *pI;

	//문법 파괴 가능
	int* pInt = (int*)pI;
	*pInt = 1000;
}

void Output(MyType mt) {
	int a = mt.a;
	int b = mt.b;
	int zzz = mt.zzz;

	mt.a = 100;//[가능]
}

//void Output(const MyType mt) {
//	int a = mt.a;
//	int b = mt.b;
//	int zzz = mt.zzz;
//
//	//mt.a = 100;//[컴파일에러]
//}

int main() {

	int a = 0;
	const int* pInt = &a;

	a = 100;
	Output(&a);
	printf("%d", a);

	return 0;
}