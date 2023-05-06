#include "CArray.h"
#include <assert.h>
#include <iostream>

void CArray::push_back(int _iData)
{
	//���������� û�ϻ�
	//����� ������
	//�Ű������� ȸ��

	int i = 0;

	if (m_iMaxCount <= m_iCurCount) {
		/*Reallocate();=resize();*/

		resize(sizeof(m_iMaxCount * 2));
	}

	m_pInt[m_iCurCount++] = _iData;
}

void CArray::resize(int _iDataCount)
{
	//�迭 ��� ����
	if (m_iMaxCount >= _iDataCount) {//�迭�� ���̸� ���� resize()�ϴ� ��쵵 ������ üũ
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

//Ŭ���� ���� ���� ���̱� ������, �̷��� ������ �������ش�.
CArray::CArray()
//initializer�� ���� ������� �ʱ�ȭ���ִ� ���� ������ ����
	:m_pInt(nullptr)
	, m_iCurCount(0)
	, m_iMaxCount(2)
{
	//�����Ҵ� ���
	//C style���� malloc() ���
	//C++ style���� new ���
	
	//=malloc(sizeof(int) * 2) = int[4byte] * 2��ŭ �Ҵ��ϰڴٴ� �ǹ�
	m_pInt = new int[2];
	
}

//Ŭ���� ���� ���� ���̱� ������, �̷��� ������ �������ش�.
CArray::~CArray()
{
	//�޸� ���� ���
	//C style���� free() ���
	//C++ style���� delete ���

	//m_pInt�� ����Ű�� ���� ���� int�� �迭�� �����ϹǷ�, delete[]�� ���
	//�迭�� �������� �ʴ´ٸ� delete�� ���
	delete[] m_pInt;

	//C���� malloc()�� �Ҵ�� �޸� ������ ���ϴ� ������ �ڷ������� �޾� ��� ����
	//C++���� Ŭ������ �����鼭, Ŭ������ ��ü ���� ��, �����ڰ� �ݵ��, ȣ��Ǿ�� ��[������ �޾ƾ� ��]
	//�����ڴ� �����Ϸ��� �ڵ����� ��ü ���� ��, ȣ��
	//�����Ϸ� ���忡��, �ش� �޸� ������ �ش� Ŭ������ ��ü�� ���� ���� �˾ƾ� ��
	//����, ������ �ڷ����� ������[�Ҵ���� �޸� ������ ���ϴ� ������ �ڷ������� �ؼ� �Ұ�]
}
