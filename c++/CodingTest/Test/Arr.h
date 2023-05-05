typedef struct _tabArr {
	int*	pInt;		//�����ּ�
	int		iCount;		//���� �־��� �ִ� �ּ�
	int		iMaxCount;	//�ִ� �ּ�
}tArr;

//�迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);
void InitArr(tArr* _pArr, unsigned int _size);

//������ �߰� �Լ�
void PushBack(tArr* _pArr, int Data);

//�迭 �޸� ���� �Լ�
void FreeArr(tArr* _pArr);

//���� �Լ�

void Sort(tArr* _pArr, void(*SortFunc)(int*, int));

void SelectionSortArr(tArr* _pArr);
void InsertionSortArr(tArr* _pArr);
void BubbleSortArr(tArr* _pArr);



void MergeSortArr(tArr* _pArr);



//���� ���� Ʈ�� �ڷ� ������ �����ؾ� ��
//���� ���� Ʈ���� �̿��� ���� �����, �̸� �̿��� �� ������ ����
void HeadSortArr(tArr* _pArr);

void QuickSortArr(tArr* _pArr);