#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->iCount = 0;
	_pList->pHeadNode = nullptr;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;
	
	_pList->pHeadNode = pNewNode;

	_pList->iCount++;
}



void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));//메모리 동적 할당
	pNode->pNextNode = nullptr;//추가되는 데이터는 무조건 마지막
	pNode->iData = _iData;//데이터 할당

	//헤더 특성상, 최초 데이터 판별
	if (_pList->iCount == 0) {
		_pList->pHeadNode = pNode;
	}
	else {
		//Ver1
		/*tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode) {
			pCurFinalNode = pCurFinalNode->pNextNode;
		}	
		pCurFinalNode->pNextNode = pNode;*/

		

		//Ver2
		tNode* pCurFinalNode = nullptr;

		for (int i = 0; i < _pList->iCount; i++) {
			if (i == 0) { 
				pCurFinalNode = _pList->pHeadNode;
			}
			else {
				pCurFinalNode = pCurFinalNode->pNextNode;
			}
		}
		pCurFinalNode->pNextNode = pNode;
	}

	_pList->iCount++;
}

//Ver1: Recursive
void Release(tNode* _pNode) {

	if (nullptr == _pNode)
		return;

	Release(_pNode->pNextNode);

	free(_pNode);
}

void ReleaseList(tLinkedList* _pList)
{
	////Ver1: Recursive
	//Release(_pList->pHeadNode);

	//Ver2: 반복문 방식
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode) {
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
