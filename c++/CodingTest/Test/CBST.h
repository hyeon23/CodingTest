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
	//��� ����
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
	//BST�� Node�� �˸� ��
private:
	tBSTNode<T1, T2>* m_pRoot;//��Ʈ ��� �ּ�
	int m_iCount;//��� �� ����

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
		tBSTNode<T1, T2>* m_pNode;// null�� ��� end iterator�� ����

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

		//������ȸ �������� ����[�ڡڡ�]
		//++: ���� �ļ���[in order successor]�� ã�� ��
		//--: ���� ������[in order predecessor]�� ã�� ��
		iterator& operator ++() {

			//���� ����� ���� �ļ��ڰ� �������� BST�� ����
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

		//root���� ���� ���س���
		while (true) {
			//Ʈ�� ���� ����
			if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			//Ʈ�� ������ ����
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

	//������ ���� ����
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = _pNode;
	
	//1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ����, ���� �ڽ��� ���� ������ ������
		//������ ������������ ���� ��尡 �ļ��ڰ� �ȴ�.
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD]) {
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD]) {
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	//2. ������ �ڽ��� ���ٸ�, ������ �θ�κ��� ���� �ڽ��� ������ ���� �ö�
		//�� ��, �θ� ��尡 �ļ��ڰ� �ȴ�.
	else {
		pSuccessor = _pNode;

		while (true)
		{
			//���̻� ���� �ö� �� ���� = ������ ��忴��
			if (pSuccessor->IsRoot())
				return nullptr;

			//�θ�κ��� ���� �ڽ����� üũ
			if (pSuccessor->IsLeftChild()) {

				//���� �ڽ��̸� �θ� �ļ���
				pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else {
				//������ �ڽ��̸� �� �ö󰣴�.
				pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
				
		}
	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	//���� �����ڴ� ��Ȯ�ϰ� �� �Լ��� ��Ī����[����]

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
	//BST�� �ᱹ Root�ۿ� ��
	//���̻� ������ ���� ������
	//���� ���������� �� ����
	
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD]) {
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	//BST�� �ᱹ Root�ۿ� ��
	//nullptr�� �����Ѿ� ��

	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _key)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	//root���� ���� ���س���
	while (true) {
		//Ʈ�� ���� ����
		if (pNode->pair.first > _key)
			node_type = NODE_TYPE::LCHILD;
		//Ʈ�� ������ ����
		else if (pNode->pair.first < _key)
			node_type = NODE_TYPE::RCHILD;
		else {
			//ã�Ҵ�. ���� ã������ ���
			break;
		}

		if (nullptr == pNode->arrNode[(int)node_type]) {
			//��ã�Ҵ�. pNode = nullptr -> enditerator
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

	//������ ��尡 ���� �ļ��� ��尡 ��
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	//1. �ڽ��� �ϳ��� ���� ���
	if (_pTargetNode->IsLeaf()) {

		//������ ��尡 ��Ʈ����(�ڽ��� ����, ��Ʈ => BST �� �����Ͱ� 1���ۿ� ������.)
		if (_pTargetNode == m_pRoot) {
			m_pRoot = nullptr;
		}
		else {
			//�θ��忡�� ������ �ڽĳ���� �ּҸ� nullptr�� �����.
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		}

		delete _pTargetNode;

		--m_iCount;
	}
	//2. �ڽ��� 2�� �ִ� ���
	else if (_pTargetNode->IsFull())
	{
		//������ �ڸ��� ���� �ļ���[or ���� ������{���û���}]�� ���� �����Ų��.
		_pTargetNode->pair = pSuccessor->pair;

		//���� �ļ��� ��带 �����Ѵ�.
		DeleteNode(pSuccessor);

		//������ ��尡 �� ���� �ļ��ڰ� �Ǿ���.
		pSuccessor = _pTargetNode;
	}
	//3. �ڽ��� 1�� �ִ� ���
	else {
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		//������ ��尡 ��Ʈ����
		if (_pTargetNode == m_pRoot) {
			//�ڽĳ��(1��)�� ��Ʈ�� �����.
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else {
			//������ ����� �θ��, ������ ����� �ڽ��� �������ش�.
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
