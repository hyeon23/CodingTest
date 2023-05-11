typedef struct _tabArr {
	int*	pInt;		//시작주소
	int		iCount;		//현재 넣어진 최대 주소
	int		iMaxCount;	//최대 주소
}tArr;

//배열 초기화 함수
void InitArr(tArr* _pArr);
void InitArr(tArr* _pArr, unsigned int _size);

//데이터 추가 함수
void PushBack(tArr* _pArr, int Data);

//배열 메모리 해제 함수
void FreeArr(tArr* _pArr);

//정렬 함수

void Sort(tArr* _pArr, void(*SortFunc)(int*, int));

void SelectionSortArr(tArr* _pArr);
void InsertionSortArr(tArr* _pArr);
void BubbleSortArr(tArr* _pArr);



void MergeSortArr(tArr* _pArr);



//완전 이진 트리 자료 구조를 구현해야 함
//완전 이진 트리를 이용해 힙을 만들고, 이를 이용해 힙 정렬을 수행
void HeadSortArr(tArr* _pArr);

void QuickSortArr(tArr* _pArr);