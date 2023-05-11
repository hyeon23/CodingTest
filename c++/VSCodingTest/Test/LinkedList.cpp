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
	tNode* pNode = (tNode*)malloc(sizeof(tNode));//�޸� ���� �Ҵ�
	pNode->pNextNode = nullptr;//�߰��Ǵ� �����ʹ� ������ ������
	pNode->iData = _iData;//������ �Ҵ�

	//��� Ư����, ���� ������ �Ǻ�
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

	//Ver2: �ݺ��� ���
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode) {
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
