#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int left, int right)
{
	return left + 3 < right;
}
void main()
{
	vector<int> v;

	v.push_back(40);
	v.push_back(46);
	v.push_back(12);
	v.push_back(80);
	v.push_back(10);
	v.push_back(47);
	v.push_back(30);
	v.push_back(55);
	v.push_back(90);
	v.push_back(53);

	cout << "[v ����]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// ��� Pred( v[i+1], v[i] ) == false
	sort(v.begin(), v.end(), Pred);
	cout << "[v ����]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// Pred(a, b) == false && Pred(b, a) == false �̸�, a == b
	if (binary_search(v.begin(), v.end(), 30))
		cout << "30 ���Ұ� �����մϴ�." << endl;
	else
		cout << "30 ���Ұ� �������� �ʽ��ϴ�." << endl;

	if (binary_search(v.begin(), v.end(), 32, Pred))
		cout << "32 ���Ұ� �����մϴ�." << endl;
	else
		cout << "32 ���Ұ� �������� �ʽ��ϴ�." << endl;

	if (binary_search(v.begin(), v.end(), 35, Pred))
		cout << "35 ���Ұ� �����մϴ�." << endl;
	else
		cout << "35 ���Ұ� �������� �ʽ��ϴ�." << endl;
}