#include "CArray.h"
#include <assert.h>
#include <iostream>

void CArray::push_back(int _iData)
{
	//지역변수는 청록색
	//멤버는 검은색
	//매개변수는 회색

	int i = 0;

	if (m_iMaxCount <= m_iCurCount) {
		/*Reallocate();=resize();*/

		resize(sizeof(m_iMaxCount * 2));
	}

	m_pInt[m_iCurCount++] = _iData;
}

void CArray::resize(int _iDataCount)
{
	//배열 축소 방지
	if (m_iMaxCount >= _iDataCount) {//배열의 길이를 같게 resize()하는 경우도 에러로 체크
		assert(nullptr);
	}

	int* pNewArr = new int[_iDataCount];

	for (size_t i = 0; i < m_iMaxCount; i++)
	{
		pNewArr[i] = m_pInt[i];
	}

	delete[] m_pInt;
		
	m_pInt = pNewArr;

	m_iMaxCount = _iDataCount;
}

//클래스 선언 범위 밖이기 때문에, 이렇게 범위를 지정해준다.
CArray::CArray()
//initializer를 선언 순서대로 초기화해주는 것이 무조건 좋음
	:m_pInt(nullptr)
	, m_iCurCount(0)
	, m_iMaxCount(2)
{
	//동적할당 방식
	//C style에선 malloc() 사용
	//C++ style에선 new 사용
	
	//=malloc(sizeof(int) * 2) = int[4byte] * 2만큼 할당하겠다는 의미
	m_pInt = new int[2];
	
}

//클래스 선언 범위 밖이기 때문에, 이렇게 범위를 지정해준다.
CArray::~CArray()
{
	//메모리 해제 방식
	//C style에선 free() 사용
	//C++ style에선 delete 사용

	//m_pInt가 가르키는 곳을 가면 int가 배열로 존재하므로, delete[]를 사용
	//배열로 존재하지 않는다면 delete를 사용
	delete[] m_pInt;

	//C에서 malloc()은 할당된 메모리 공간을 원하는 포인터 자료형으로 받아 사용 가능
	//C++에서 클래스가 나오면서, 클래스는 객체 생성 시, 생성자가 반드시, 호출되어야 함[보장을 받아야 함]
	//생성자는 컴파일러가 자동으로 객체 생성 시, 호출
	//컴파일러 입장에선, 해당 메모리 공간이 해당 클래스의 객체가 들어올 것을 알아야 함
	//따라서, 포인터 자료형이 고정됨[할당받은 메모리 공간을 원하는 포인터 자료형으로 해석 불가]
}
