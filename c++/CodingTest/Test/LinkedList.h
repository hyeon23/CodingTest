typedef struct _tagNode {
	int			iData;
	_tagNode* pNextNode;
	//자신의 클래스 내부에서 자기 자신 타입 자료형의 객체를 선언하면 안된다.
	//그래서 tNode는 쓸 수 없고, _tagNode를 써줘야 한다.
}tNode;

typedef struct _tagList {
	int			iCount;//노드 개수
	tNode*		pHeadNode;//첫번재 노드의 주소
}tLinkedList;

//연결 리스트 초기화
void InitList(tLinkedList* _pList);

//연결형 리스트 앞에 데이터 추가
void PushFront(tLinkedList* _pList, int _iData);

//연결형 리스트 뒤에 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);

//연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);

