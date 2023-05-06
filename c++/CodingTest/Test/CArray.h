#pragma once
class CArray
{
private:
	int*	m_pInt;
	int		m_iCurCount;
	int		m_iMaxCount;

public:
	void push_back(int _iData);
	void resize(int _iDataCount);//사용자가 미리 공간을 크게 넓히고 싶다면, 먼저 공간을 넓히도록 resize()함수를 공개
//생성자는 public 필드에 둔다. 
public:
	//생성자
	CArray();
	//소멸자
	~CArray();
};

