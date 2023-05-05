typedef struct _tagNode {
	int			iData;
	_tagNode* pNextNode;
	//�ڽ��� Ŭ���� ���ο��� �ڱ� �ڽ� Ÿ�� �ڷ����� ��ü�� �����ϸ� �ȵȴ�.
	//�׷��� tNode�� �� �� ����, _tagNode�� ����� �Ѵ�.
}tNode;

typedef struct _tagList {
	int			iCount;//��� ����
	tNode*		pHeadNode;//ù���� ����� �ּ�
}tLinkedList;

//���� ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);

//������ ����Ʈ �տ� ������ �߰�
void PushFront(tLinkedList* _pList, int _iData);

//������ ����Ʈ �ڿ� ������ �߰�
void PushBack(tLinkedList* _pList, int _iData);

//������ ����Ʈ �޸� ����
void ReleaseList(tLinkedList* _pList);

