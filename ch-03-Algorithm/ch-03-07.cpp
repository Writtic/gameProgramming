#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main( )
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(60);

    vector<int> v3(10); //size: 10인 vector 생성, 0으로 초기화
    vector<int>::iterator iter_end;

    iter_end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "합집합[v3.begin(), iter_end): ";
    for(vector<int>::iterator iter=v3.begin(); iter != iter_end; ++iter)
        cout << *iter <<" ";
    cout << endl;

    cout << "v3: ";
    for(vector<int>::size_type i = 0; i < v3.size(); ++i)
        cout << v3[i] <<" ";
    cout << endl;

    iter_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "교집합[v3.begin(), iter_end): ";

    for(vector<int>::iterator iter=v3.begin(); iter != iter_end; ++iter)
        cout << *iter <<" ";
    cout << endl;
    // 활동 (ch-03-07):  iter_end를 v3.end()로 변경해보자. 쓰레기 값이 잘 들어있는지 확인해보자.
    for(vector<int>::iterator iter=v3.begin(); iter != v3.end(); ++iter)
        cout << *iter <<" ";
    cout << endl;
}
