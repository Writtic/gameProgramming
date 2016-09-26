#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 마지막 데이터를 쓰레기값으로 남겨서 메모리 양을 줄이는 비싼 연산을 하지 않음.
int main( )
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    vector<int>::iterator iter_end;
    iter_end = remove(v.begin(), v.end(), 30);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] <<" ";
    cout << endl;

    cout << "remove 후 [v.begin(), iter_end) 순차열: ";
    // 활동 (ch-03-03):  iter_end를 v.end()로 변경해보자.
    // 두 케이스를 비교하여 알아두자! - 시험
    for(vector<int>::iterator iter=v.begin(); iter != iter_end; ++iter)
        cout << *iter <<" ";
    cout << endl;
    for(vector<int>::iterator iter=v.begin(); iter != v.end(); ++iter)
        cout << *iter <<" ";
    cout << endl;
}
