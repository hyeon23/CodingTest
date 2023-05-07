#pragma once

template<typename T>
class Node {
public:
	T data;
	//���ο���, �ڱ� �ڽ� ���ø� Ÿ�� ���� ����
	Node/*<T>*/* pPrev;
	Node/*<T>*/* pNext;
	

public:
	//������ �����ε�
	Node() 
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
		
	}

	Node(const T& _data, Node<T>* _pPrev, Node<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}

	~Node() {

	}
};

template<typename T>
class CLinkedList
{
private:
	Node<T>* m_pHead;//�ܺο���, ���� ���ø� Ÿ�� �ݵ�� ����
	Node<T>* m_pTail;//�ܺο���, ���� ���ø� Ÿ�� �ݵ�� ����
	int m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);

public:
	CLinkedList();
	~CLinkedList();
};

template<typename T>
void CLinkedList<T>::push_back(const T& _data)
{
	//�Էµ� �����͸� ������ ��带 �����Ҵ�
	Node<T>* pNewNode = new Node<T>(_data, nullptr, nullptr);

	// ó�� �Էµ� ������ ��,
	if (nullptr == m_pHead) {
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else {
		//tail ptr�� �̿��� ���� ��尣 ����
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		m_pTail = pNewNode;
	}
	m_iCount++;
}

template<typename T>
inline void CLinkedList<T>::push_front(const T& _data)
{
	//������ ��忡�� Head�� �̵��ϴ� �����ʹ� ������� �ʴ´ٰ� ����
	//�Էµ� �����͸� ������ ��带 �����Ҵ�
	//���� ������ ����� pNext�� ����Ʈ�� ��忴�� ��带 ����Ŵ
	Node<T>* pNewNode = new Node<T>(_data, nullptr, m_pHead);
	
	//����Ʈ�� ��忴�� ����� pPrev�� ���� ������ ��带 ����Ŵ
	m_pHead->pPrev = pNewNode;

	//���� ������ ��带 ����Ʈ�� ��尡 ����Ŵ
	m_pHead = pNewNode;

	//������ ī��Ʈ ����
	m_iCount++;
}

template<typename T>
inline CLinkedList<T>::CLinkedList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{
}

template<typename T>
inline CLinkedList<T>::~CLinkedList()
{
	Node<T>* pDeleteNode = m_pHead;

	while (pDeleteNode) {
		Node<T>* pNextNode = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNextNode;
	}
}
