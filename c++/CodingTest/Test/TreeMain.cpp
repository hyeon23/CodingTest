#include <iostream>

#include <map>
#include <set>
#include <string>

using std::wcout;
using std::wcin;
using std::endl;

using std::wstring;

using std::map;
using std::make_pair;
//�̹� STL�� ������[map]

using std::set;

#define MAN		1
#define WOMAN	2

struct tStdInfo {
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo() 
		: szName{}
		, age(0)
		, gender(0)
	{

	}

	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

template<typename T>
struct pair {
	const T* first;
	tStdInfo secont;
};

int main() {

	//set
	//-Red-Black Tree: �츮�� ������ BS ����� �ڷᱸ���� ����� �����̳�
	//-map�� �ַ� ���̰�, set�� �� ������ ����
	set<int> setInt;

	setInt.insert(100); //root:100
	setInt.insert(200); 
	setInt.insert(300); 
	setInt.insert(400); 
	setInt.insert(500); 
	setInt.insert(600); 
	setInt.insert(700); 
	setInt.insert(800); 
	setInt.insert(900); 

	//map
	//map�� type�� 2���� ��� ��
	//map�� key & value�� �����͸� ����
	//�л� ����[����, ����, �̸�]�� ����ü�� ����� ������ ����
	//map<string name, Data data> studentData;
	//Ű ���� �������� ���ĵ�

	//map ����(����)
	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info1(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	//map ������ ����
	//-map�� �̸��� key ������ �����͸� �־��� ��
	//-make_pair()�� �� �����͸� ���� <key, value> ������ Pair[¦]�� ����
	mapData.insert(make_pair(L"ȫ�浿", info1));
	mapData.insert(make_pair(L"������", info2));

	//map Ž��(Ű�� �������)
	//-key ���� �־��ָ� �ȴ�.
	//-<key, pair[key, value]>
	//-���� ���� �ش� pair[key, value]�� ī��Ű�� iterator

	map<const wchar_t*, tStdInfo>::iterator mapIter;
	mapIter = mapData.find(L"ȫ�浿");
	//mapIter = mapData.find(L"���浿"); 
	//�����Ͱ� ������ end iterator ��ȯ

	//(*mapIter) = map
	//map�� first[key], second[value] �ڷḦ ����
	//map.first, map.second
	//���� ��, ȭ��ǥ�� ���

	_wsetlocale(LC_ALL, L"korean");


	mapIter->first;//const wchar_t
	mapIter->second;//tStdInfo

	if (mapIter == mapData.end()) {
		wcout << L"�����͸� ã�� �� ����." << endl;
	}
	else {
		wcout << L"�̸� : " << mapIter->second.szName << endl;
		wcout << L"���� : " << mapIter->second.age << endl;
		wcout << L"���� : " << mapIter->second.gender << endl;
	}

	//map���� key ������ �����Ͱ� �ƴ� wstring�� ����ϴ� ����
	//��, ����� map<const wchar_t*, tStdInfo>�̶� ���ڿ��� ���� �ƴ� �ּҸ� �������� ã�� ���� 
	wchar_t nsArr[20] = L"������";
	//�� ��� ���ڿ��� �ּҰ� �޶� ã�� ����

	map<wstring, tStdInfo> manStdInfo;

	//���� �������� �ּҸ� �Űܿ��� ���� �ƴ� = �����ڰ� ������ ��ü������ ������ �ִ� ���� �ȿ� ���ڿ��� ������ ��
	//�ּҸ� ����Ű�� ���°� �ƴ� ��ü������ ����

	wstring str;//�����迭, vector<wchar_t>�� ���� ����
	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	wstring str2;

	if (str == str2) {//>, <, >=, <= ���� �̹� �Ϸ�

	}

	//map ���ø��� ù���� Ÿ��(key)�� �ݵ�� 
	//��� ��, �(<, >, <=, >=, ==, !=) ������ �����ε��� �ۼ��Ǿ�� ��



}