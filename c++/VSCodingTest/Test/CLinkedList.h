#pragma once

template<typename T>
class Node {
public:
	T data;
	//내부에선, 자기 자신 템플릿 타입 생략 가능
	Node/*<T>*/* pPrev;
	Node/*<T>*/* pNext;
	

public:
	//생성자 오버로딩
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
	Node<T>* m_pHead;//외부에선, 남의 템플릿 타입 반드시 선언
	Node<T>* m_pTail;//외부에선, 남의 템플릿 타입 반드시 선언
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
	//입력된 데이터를 저장할 노드를 동적할당
	Node<T>* pNewNode = new Node<T>(_data, nullptr, nullptr);

	// 처음 입력된 데이터 시,
	if (nullptr == m_pHead) {
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else {
		//tail ptr을 이용한 쉬운 노드간 연결
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		m_pTail = pNewNode;
	}
	m_iCount++;
}

template<typename T>
inline void CLinkedList<T>::push_front(const T& _data)
{
	//최초의 노드에서 Head로 이동하는 포인터는 사용하지 않는다고 가정
	//입력된 데이터를 저장할 노드를 동적할당
	//새로 생성된 노드의 pNext가 리스트의 헤드였던 노드를 가리킴
	Node<T>* pNewNode = new Node<T>(_data, nullptr, m_pHead);
	
	//리스트의 헤드였던 노드의 pPrev가 새로 생성될 노드를 가르킴
	m_pHead->pPrev = pNewNode;

	//새로 생성된 노드를 리스트의 헤드가 가리킴
	m_pHead = pNewNode;

	//데이터 카운트 증가
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
