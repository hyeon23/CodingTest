#include <iostream>
#include <map>

#include "CBST.h"

using std::wcout;
using std::endl;
using std::map;
using std::make_pair;

int main() {
	CBST<int, int> bstInt;	

	bstInt.insert(make_bstpair(100, 0));//			100
	bstInt.insert(make_bstpair(150, 0));//		50		150
	bstInt.insert(make_bstpair(50, 0));//	25		125		175
	bstInt.insert(make_bstpair(25, 0));
	bstInt.insert(make_bstpair(75, 0));
	bstInt.insert(make_bstpair(125, 0));
	bstInt.insert(make_bstpair(175, 0));

	CBST<int, int>::iterator Iter = bstInt.begin();
	Iter = bstInt.find(150);
	Iter = bstInt.erase(Iter);

	Iter = bstInt.find(100);
	Iter = bstInt.erase(Iter);

	(*Iter).first;
	
	//Iter->의 연산자로 돌아온 것이 Pair의 주소 값
	//주소 값을 리턴하므로, 원래 표현은 이게 맞음
	//Iter->->first;
	//하지만 생략해 표현하도록 문법적 보정
	Iter->first;
	
	(*Iter).second;
	Iter->second;

	tPair<int, int> pair;
	tPair<int, int>* pPair = &pair;
	pPair->first;
	pPair->second;



	/*for (bstIter = bstInt.begin(); bstIter != bstInt.end(); ++bstIter) {
		wcout << bstIter->first << bstIter->second << endl;
	}*/

	return 0;

	map<int, int> mapInt;
	mapInt.insert(make_pair(100, 100));

	map<int, int>::iterator iter = mapInt.find(100);

	
}