#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
// for greater in VC2012
#include <functional>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	//받는 입장에서는 함수 객체, 클래스를 받아다 씀.
	sort(v.begin(), v.end(), less<int>() /*myLess*/); // 오름차순 정렬  less<int> myLess = less<int>();
	//sort 내부에는 myLess(x, y); 가 내부에 있을거라 상상
	// bool myLess(x, y) { return x < y }
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	//std::
	sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
