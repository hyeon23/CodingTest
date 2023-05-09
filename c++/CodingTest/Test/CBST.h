#include <assert.h>

#pragma once
enum class NODE_TYPE {
	PARENT,//0
	LCHILD,//1
	RCHILD,//2
	END,
};

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second) {
	return tPair<T1, T2>{ _first, _second };
}

template<typename T1, typename T2>
struct tBSTNode {
	
	//data[Parir]
	tPair<T1, T2> pair;

	////ParentPtr
	//tBSTNode* pParent;
	////leftChildPtr
	//tBSTNode* pLeftChild;
	////rightChildPtr
	//tBSTNode* pRightChild;
	//묶어서 선언
	tBSTNode* arrNode[(int)NODE_TYPE::END];

	bool IsRoot() {
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT]) {
			return true;
		}
		return false;
	}

	bool IsLeftChild() {

		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}

	bool IsRightChild() {

		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}

	bool IsLeaf() {
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

	bool IsFull() {
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

public:
	tBSTNode()
		: pair()
		, arrNode{}
	{

	}

	tBSTNode(tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: pair(_pair)
		, arrNode{ _pParent , _pLChild, _pRChild }
	{

	}
};

template <typename T1, typename T2>
class CBST
{
	//BST는 Node만 알면 됨
private:
	tBSTNode<T1, T2>* m_pRoot;//루트 노드 주소
	int m_iCount;//노드 총 개수

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode);

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _key);
	iterator erase(const iterator& _iter);

private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

public:
	CBST() 
		:m_pRoot(nullptr)
		,m_iCount(0)
	{

	}

	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;
		tBSTNode<T1, T2>* m_pNode;// null인 경우 end iterator로 간주

	public:
		bool operator ==(const CBST<T1, T2>::iterator& _other) {

			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode) {
				return true;
			}
			else {
				return false;
			}

		}

		bool operator !=(const CBST<T1, T2>::iterator& _otherIter) {

			return !(*this == _otherIter);
		}

		const tPair<T1, T2>& operator *() {
			
			//iter = nullptr = end iterator
			assert(m_pNode);
			return m_pNode->pair;
		}

		const tPair<T1, T2>* operator ->() {

			//iter = nullptr = end iterator
			assert(m_pNode);

			return &m_pNode->pair;
		}

		//중위순회 기준으로 다음[★★★]
		//++: 중위 후속자[in order successor]를 찾는 것
		//--: 중위 선행자[in order predecessor]를 찾는 것
		iterator& operator ++() {

			//현재 노드의 중위 후속자가 누구인지 BST에 물음
			m_pNode = m_pBST->GetInorderSuccessor(m_pNode);
			return *this;
		}


	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{ }

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{ }

		friend class CBST<T1, T2>;
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	if (nullptr == m_pRoot) {
		m_pRoot = pNewNode;
	}
	else {
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		//root에서 부터 비교해나감
		while (true) {
			//트리 왼쪽 삽입
			if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			//트리 오른쪽 삽입
			else if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else
				return false;

			if (nullptr == pNode->arrNode[(int)node_type]) {
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else {
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	//데이터 개수 증가
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = _pNode;
	
	//1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서, 왼쪽 자식이 없을 때까지 내려감
		//끝까지 내려갔을때의 현재 노드가 후속자가 된다.
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD]) {
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD]) {
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	//2. 오른쪽 자식이 없다면, 본인이 부모로부터 왼쪽 자식일 때까지 위로 올라감
		//그 때, 부모 노드가 후속자가 된다.
	else {
		pSuccessor = _pNode;

		while (true)
		{
			//더이상 위로 올라갈 수 없다 = 마지막 노드였다
			if (pSuccessor->IsRoot())
				return nullptr;

			//부모로부터 왼쪽 자신인지 체크
			if (pSuccessor->IsLeftChild()) {

				//왼쪽 자식이면 부모가 후속자
				pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else {
				//오른쪽 자식이면 또 올라간다.
				pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
				
		}
	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	//중위 선행자는 정확하게 이 함수와 대칭구조[숙제]

	tBSTNode<T1, T2>* pSuccessor = _pNode;

	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::LCHILD]) {
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::RCHILD]) {
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::RCHILD];
		}
	}

	else {
		pSuccessor = _pNode;

		while (true)
		{
			if (pSuccessor->IsRoot())
				return nullptr;

			if (pSuccessor->IsRightChild()) {

				pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else {
				pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}

		}
	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	//BST는 결국 Root밖에 모름
	//더이상 왼쪽이 없을 때까지
	//왼쪽 리프노드까지 쭉 돌진
	
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD]) {
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	//BST는 결국 Root밖에 모름
	//nullptr을 가르켜야 함

	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _key)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	//root에서 부터 비교해나감
	while (true) {
		//트리 왼쪽 삽입
		if (pNode->pair.first > _key)
			node_type = NODE_TYPE::LCHILD;
		//트리 오른쪽 삽입
		else if (pNode->pair.first < _key)
			node_type = NODE_TYPE::RCHILD;
		else {
			//찾았다. 현재 찾으려는 노드
			break;
		}

		if (nullptr == pNode->arrNode[(int)node_type]) {
			//못찾았다. pNode = nullptr -> enditerator
			pNode = nullptr;
			break;
		}
		else {
			pNode = pNode->arrNode[(int)node_type];
		}
	}

	return iterator(iterator, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{
	assert(this == _iter.m_pBST);

	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{

	//삭제할 노드가 중위 후속자 노드가 됨
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	//1. 자식이 하나도 없는 경우
	if (_pTargetNode->IsLeaf()) {

		//삭제할 노드가 루트였다(자식이 없고, 루트 => BST 안 데이터가 1개밖에 없었다.)
		if (_pTargetNode == m_pRoot) {
			m_pRoot = nullptr;
		}
		else {
			//부모노드에서 삭제될 자식노드의 주소를 nullptr로 만든다.
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		}

		delete _pTargetNode;

		--m_iCount;
	}
	//2. 자식이 2개 있는 경우
	else if (_pTargetNode->IsFull())
	{
		//삭제될 자리에 중위 후속자[or 중위 선행자{선택사항}]의 값을 복사시킨다.
		_pTargetNode->pair = pSuccessor->pair;

		//중위 후속자 노드를 삭제한다.
		DeleteNode(pSuccessor);

		//삭제할 노드가 곧 중위 후속자가 되었다.
		pSuccessor = _pTargetNode;
	}
	//3. 자식이 1개 있는 경우
	else {
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		//삭제할 노드가 루트였다
		if (_pTargetNode == m_pRoot) {
			//자식노드(1개)를 루트로 만든다.
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else {
			//삭제될 노드의 부모와, 삭제될 노드의 자식을 연결해준다.
			if (_pTargetNode->IsLeftChild()) {
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}
			else {
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}

			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}

		delete _pTargetNode;

		--m_iCount;
	}

	return pSuccessor;
}
