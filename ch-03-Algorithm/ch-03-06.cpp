#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary Search
bool Pred(int left, int right)
{
	// 왼쪽이 나보다 3정도 큰 것은 무시
  return left + 3 < right;
}

int main()
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

  cout << "[v 원본]: ";

  for (vector<int>::size_type i = 0; i < v.size(); ++i) cout << v[i] << " ";
  cout << endl;

  // 모든 Pred( v[i+1], v[i] ) == false
  sort(v.begin(), v.end(), Pred);
  cout << "[v 정렬]: ";

  for (vector<int>::size_type i = 0; i < v.size(); ++i) cout << v[i] << " ";
  cout << endl;

	
  // Pred(a, b) == false && Pred(b, a) == false 이면, a == b
  if (binary_search(v.begin(), v.end(), 30))
		cout << "30 원소가 존재합니다." << endl;
  else
		cout << "30 원소가 존재하지 않습니다." << endl;

  if (binary_search(v.begin(), v.end(), 32, Pred))
		cout << "32 원소가 존재합니다." << endl;
  else
		cout << "32 원소가 존재하지 않습니다." << endl;
	// 범위를 벗어남.(값을 찾아도 범위로 지정해서 찾을 수 있음)
  if (binary_search(v.begin(), v.end(), 35, Pred))
		cout << "35 원소가 존재합니다." << endl;
  else
		cout << "35 원소가 존재하지 않습니다." << endl;
}
