#include "Arr.h"
#include <iostream>

//배열 상태 출력 함수
void PrintArr(tArr* _pArr) {
	printf("\n");
	for (int i = 0; i < _pArr->iCount; i++) {
		printf("%d ", _pArr->pInt[i]);
	}
	printf("\n");
}

//배열 초기화 함수
void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void InitArr(tArr* _pArr, unsigned int _size) {
	_pArr->pInt = (int*)malloc(_size);
	_pArr->iCount = 0;
	_pArr->iMaxCount = _size / sizeof(int);
}

void ReAllocate(tArr* _pArr)
{
	//내가 원하는 힙상의 주소를 지정해서 할당받을 수 있다면 편함
	//하지만 그렇지 못함

	//따라서, 새로운 배열을 만들고, 거기에 넣어줘야 함
	//따라서, 애초에 배열의 크기가 부족할 듯 싶으면, 애초에 배열의 크기를 크게 만들어야 함

	//1. 2배 더 큰 공간을 동적 할당
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	//2. 리포인팅 전, 값 복사
	for (int i = 0; i < _pArr->iCount; i++) {
		pNew[i] = _pArr->pInt[i];
	}

	//3. 리포인팅 전, 값 복사 기존에 할당된 힙 영역 메모리 해제
	free(_pArr->pInt);

	//4. 리포인팅
	_pArr->pInt = pNew;

	//5. 공간 확장에 따른 공간 최댓값 설정
	_pArr->iMaxCount *= 2;


	//힙손상: 포인터를 잘못써서 발생하는 주소 침범 오류
	//문법 오류가 아니라 컴파일 에러도 안뜨고, 문제 발견하기 쉽지 않음
	//굉장히 나중에 발생할 경우 문제 발생지 파악이 답도없어짐
	//내가 실수했는데, 다른 사람 코드에서 Crush가 터지는 경우가 있음
	//내가 작성한 부분에서 문제가 생겨도 문제를 못찾겠는 경우, 힙손상을 의심해보자
}

void PushBack(tArr* _pArr, int _iData)
{
	//힙 영역에 할당한 데이터 공간이 다 넣음
	if (_pArr->iCount >= _pArr->iMaxCount) {
		//재할당
		ReAllocate(_pArr);
	}

	_pArr->pInt[_pArr->iCount] = _iData;
	_pArr->iCount++;
}

//배열 메모리 해제 함수
void FreeArr(tArr* _pArr)
{
	_pArr->iMaxCount = NULL;
	_pArr->iCount = NULL;
	free(_pArr->pInt);
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCount);
}

void SelectionSortArr(tArr* _pArr)
{
	for (size_t i = 0; i < _pArr->iCount; i++)
	{
		int min_value_index = i;

		for (size_t j = i + 1; j < _pArr->iCount; j++)
		{
			if (_pArr->pInt[i] > _pArr->pInt[j]) {
				min_value_index = j;
			}
		}

		int temp = _pArr->pInt[min_value_index];
		_pArr->pInt[min_value_index] = _pArr->pInt[i];
		_pArr->pInt[i] = temp;

		PrintArr(_pArr);
	}
}

void InsertionSortArr(tArr* _pArr)
{
	for (int key = 1; key < _pArr->iCount; key++)
	{
		int temp = _pArr->pInt[key];

		for (int j = key - 1; j >= 0; j--)
		{
			if (_pArr->pInt[j] > temp) {

				_pArr->pInt[j + 1] = _pArr->pInt[j];
				_pArr->pInt[j] = temp;
			}
		}

		PrintArr(_pArr);
	}
}

void BubbleSortArr(tArr* _pArr)
{
	for (size_t i = 0; i < _pArr->iCount - 1; i++)
	{
		for (size_t j = 0; j < _pArr->iCount - i - 1; j++)
		{
			if (_pArr->pInt[j] > _pArr->pInt[j + 1]) {
				int temp = _pArr->pInt[j + 1];
				_pArr->pInt[j + 1] = _pArr->pInt[j];
				_pArr->pInt[j] = temp;
				
				PrintArr(_pArr);

			}
		}
	}
}
