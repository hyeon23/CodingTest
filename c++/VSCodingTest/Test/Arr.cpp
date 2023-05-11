#include "Arr.h"
#include <iostream>

//�迭 ���� ��� �Լ�
void PrintArr(tArr* _pArr) {
	printf("\n");
	for (int i = 0; i < _pArr->iCount; i++) {
		printf("%d ", _pArr->pInt[i]);
	}
	printf("\n");
}

//�迭 �ʱ�ȭ �Լ�
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
	//���� ���ϴ� ������ �ּҸ� �����ؼ� �Ҵ���� �� �ִٸ� ����
	//������ �׷��� ����

	//����, ���ο� �迭�� �����, �ű⿡ �־���� ��
	//����, ���ʿ� �迭�� ũ�Ⱑ ������ �� ������, ���ʿ� �迭�� ũ�⸦ ũ�� ������ ��

	//1. 2�� �� ū ������ ���� �Ҵ�
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	//2. �������� ��, �� ����
	for (int i = 0; i < _pArr->iCount; i++) {
		pNew[i] = _pArr->pInt[i];
	}

	//3. �������� ��, �� ���� ������ �Ҵ�� �� ���� �޸� ����
	free(_pArr->pInt);

	//4. ��������
	_pArr->pInt = pNew;

	//5. ���� Ȯ�忡 ���� ���� �ִ� ����
	_pArr->iMaxCount *= 2;


	//���ջ�: �����͸� �߸��Ἥ �߻��ϴ� �ּ� ħ�� ����
	//���� ������ �ƴ϶� ������ ������ �ȶ߰�, ���� �߰��ϱ� ���� ����
	//������ ���߿� �߻��� ��� ���� �߻��� �ľ��� �䵵������
	//���� �Ǽ��ߴµ�, �ٸ� ��� �ڵ忡�� Crush�� ������ ��찡 ����
	//���� �ۼ��� �κп��� ������ ���ܵ� ������ ��ã�ڴ� ���, ���ջ��� �ǽ��غ���
}

void PushBack(tArr* _pArr, int _iData)
{
	//�� ������ �Ҵ��� ������ ������ �� ����
	if (_pArr->iCount >= _pArr->iMaxCount) {
		//���Ҵ�
		ReAllocate(_pArr);
	}

	_pArr->pInt[_pArr->iCount] = _iData;
	_pArr->iCount++;
}

//�迭 �޸� ���� �Լ�
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
