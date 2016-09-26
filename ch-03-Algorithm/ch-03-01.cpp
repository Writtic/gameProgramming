#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int n)
{
    cout << n << " ";
}
int main( )
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    v2.push_back(60);
    v2.push_back(70);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    vector<int> v3;
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] <<" ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] <<" ";
    cout << endl;

    //구간 [v1.being(), v1.end)와 구간 [v2.begin(), v2.begin()+3)을 비교 합니다.
    if( equal(v1.begin(), v1.end(), v2.begin()) )
    // 갯수에서 몇개를 비교할건지 v1이 결정하므로 v2.end()가 필요없다.
        cout << "두 순차열은 같습니다." << endl;
    // 각각의 이터레이터안의 원소를 출력
    for_each(v2.begin(), v2.begin()+3, Print);
    cout << endl;
    for_each(v2.begin(), v2.begin()+6, Print);
    cout << endl;
    //[v.begin(), v.end()) 구간의 원소 출력
    for_each(v2.begin(), v2.end(), Print);
    cout << endl;

    vector<int>::iterator iter;
    iter = search(v2.begin(), v2.end(), v3.begin(), v3.end());
    if( iter != v2.end() )
    {
        // 일치하는 첫 번째 순차열의 첫 원소의 반복자 iter
        cout << "iter : " << *iter << endl;
        cout << "iter-1 : " <<*(iter-1) << endl;
        cout << "iter+1 : " <<*(iter+1) << endl;;
    }
}
