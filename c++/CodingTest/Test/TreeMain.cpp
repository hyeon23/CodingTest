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
//이미 STL로 구현됨[map]

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
	//-Red-Black Tree: 우리가 생각한 BS 기반의 자료구조를 사용한 컨테이너
	//-map이 주로 쓰이고, set은 잘 쓰이지 않음
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
	//map은 type을 2개를 줘야 함
	//map은 key & value로 데이터를 저장
	//학생 정보[나이, 성별, 이름]의 구조체를 만들고 저장을 원함
	//map<string name, Data data> studentData;
	//키 값을 기준으로 정렬됨

	//map 생성(선언)
	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info1(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	//map 데이터 삽입
	//-map에 이름을 key 값으로 데이터를 넣어준 것
	//-make_pair()란 두 데이터를 묶어 <key, value> 형태의 Pair[짝]을 만듬
	mapData.insert(make_pair(L"홍길동", info1));
	mapData.insert(make_pair(L"이지혜", info2));

	//map 탐색(키를 기반으로)
	//-key 값을 넣어주면 된다.
	//-<key, pair[key, value]>
	//-리턴 값은 해당 pair[key, value]를 카르키는 iterator

	map<const wchar_t*, tStdInfo>::iterator mapIter;
	mapIter = mapData.find(L"홍길동");
	//mapIter = mapData.find(L"강길동"); 
	//데이터가 없으면 end iterator 반환

	//(*mapIter) = map
	//map은 first[key], second[value] 자료를 가짐
	//map.first, map.second
	//조합 시, 화살표로 사용

	_wsetlocale(LC_ALL, L"korean");


	mapIter->first;//const wchar_t
	mapIter->second;//tStdInfo

	if (mapIter == mapData.end()) {
		wcout << L"데이터를 찾을 수 없다." << endl;
	}
	else {
		wcout << L"이름 : " << mapIter->second.szName << endl;
		wcout << L"나이 : " << mapIter->second.age << endl;
		wcout << L"성별 : " << mapIter->second.gender << endl;
	}

	//map에서 key 값으로 포인터가 아닌 wstring을 사용하는 이유
	//단, 현재는 map<const wchar_t*, tStdInfo>이라 문자열의 값이 아닌 주소를 기준으로 찾고 있음 
	wchar_t nsArr[20] = L"이지혜";
	//이 경우 문자열의 주소가 달라 찾지 못함

	map<wstring, tStdInfo> manStdInfo;

	//문자 데이터의 주소를 옮겨오는 것이 아닌 = 연산자가 본인이 자체적으로 가지고 있는 공간 안에 문자열을 가지고 옴
	//주소를 가르키는 형태가 아닌 자체적으로 관리

	wstring str;//가변배열, vector<wchar_t>와 가장 유사
	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	wstring str2;

	if (str == str2) {//>, <, >=, <= 구현 이미 완료

	}

	//map 템플릿의 첫번재 타입(key)는 반드시 
	//대소 비교, 등가(<, >, <=, >=, ==, !=) 연산자 오버로딩이 작성되어야 함



}