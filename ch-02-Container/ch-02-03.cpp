#include <iostream>
#include <vector>
#include <algorithm> // find ����
using namespace std;

int main()
{
	vector<float> v;

	v.push_back(10.0);
	v.push_back(20.0);
	v.push_back(30.0);
	v.push_back(40.0);
	v.push_back(50.0);

	vector<float>::iterator iter; // iter에는 쓰레기값이 들어가 있겠죵.
	iter = find(v.begin(), v.end(), 20.0); //[begin, end)에서 20 찾기, 있으면 위치포인트를 리턴
	cout << *iter << endl;

	iter = find(v.begin(), v.end(), 19.999999999999999); //[begin, end)에서 100 찾기

	if (iter == v.end()) // 100이 없으면 iter==v.end()임, 리턴값이 v.end()면 데이터가 없다는 뜻
		// [begin, end) 이런 개념
		// cout << "100이 없음!" << endl;
		cout << "19.999999999999999이 없음!" << endl;
	else
		cout << *iter << endl;
}

// 실습 (ch-02-03): 정수형을 실수(float)형으로 바꾸어 검색하자.
//vector<int> -> vector<float>
// 실습 (ch-02-03): 실수형 100 대신 19.999999999999999 를 검색하자.
// 9가 충분히 많으면 floating point 오차가 생기면 20으로 인식하고 찾아버린다.
