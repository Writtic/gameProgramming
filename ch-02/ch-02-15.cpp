#include <iostream>
#include <set>
using namespace std;

void main( )
{
    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;
    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "원소 50의 개수: " << s.count(50) << endl;
    cout << "원소 100의 개수: " << s.count(100) << endl;
	
    iter = s.find(30); // 30의 반복자를 반환
    if( iter != s.end() )
        cout << *iter <<"가 s에 있다!" << endl;
    else
        cout << "20이 s에 없다!" << endl;
	
    // 30과 50의 비교
    cout << (!s.key_comp()(30, 50) && !s.key_comp()(50,30)) << endl; //다르다
    // 30과 30의 비교
    cout << (!s.key_comp()(30, 30) && !s.key_comp()(30,30)) << endl; //같다(equivalence)
}
