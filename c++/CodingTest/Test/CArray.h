#pragma once
class CArray
{
private:
	int*	m_pInt;
	int		m_iCurCount;
	int		m_iMaxCount;

public:
	void push_back(int _iData);
	void resize(int _iDataCount);//����ڰ� �̸� ������ ũ�� ������ �ʹٸ�, ���� ������ �������� resize()�Լ��� ����
//�����ڴ� public �ʵ忡 �д�. 
public:
	//������
	CArray();
	//�Ҹ���
	~CArray();
};

