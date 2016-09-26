#include <iostream>
#include <vector>
using namespace std;
// 벡터에 숫자가 들어있을 경우
// 중간에 숫자를 추가하거나
// 벡터를 추가하거나
// 벡터를 통째로 드러내거나
int main( )
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;
    vector<int>::iterator iter2;

    vector<int> v2;
    v2.assign( v.begin(), v.end() );  // v2에 순차열 [v.begin(), v.end())을 할당.
    for( iter = v2.begin(); iter != v2.end() ; ++iter)
        cout << *iter << " "; // v2 출력
    cout << endl;

    iter = v.begin()+2; // 30을 가리킴

    // iter가 가리키는 위치에 정수 100을 삽입.
    // iter2는 삽입한 정수를 가리키는 반복자.
    // 현 위치의 숫자포함 뒷 숫자들은 뒤로 밀려나고 100이 삽입됨.
    iter2 = v.insert(iter, 100);

    for( iter = v.begin(); iter != v.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "iter2: " << *iter2 << endl;

    iter = v2.begin()+1;  // {10, 20, 30, 40, 50}
    // iter가 가리키는 위치에 [v.begin(), v.end()) 구간의 원소를 삽입.
    v2.insert(iter, v.begin(), v.end()); // {10, [v.begin(), v,end()) 20, 30, 40, 50}

    for( iter = v2.begin(); iter != v2.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    iter = v2.begin()+2; // { 10, 10, 20, 100, …}
    // iter가 가리키는 위치의 원소를 제거합니다.
    iter2 = v2.erase(iter);

    for( iter = v2.begin(); iter != v2.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    // [v2.begin()+5, v2.end()) 구간의 원소를 제거합니다.
    iter2 = v2.erase(v2.begin()+2, v2.end()-2); // iter2는 다음 원소 v.end()

    for( iter = v2.begin(); iter != v2.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    if( v == v2 )
        cout << "v1 == v2" << endl;
    if( v != v2 )
        cout << "v1 != v2" << endl;
    if( v < v2 )
        cout << "v1 < v2" << endl;
    if( v > v2 )
        cout << "v1 > v2" << endl;
}
