#include <iostream>
#include <set>
using namespace std;

// bool func(x, y) { // x > y ?
//     if(x > y) return true;
//     else return false;
// }
// x == y ? // 이것도 functor로 짜죠..? 아니 할게 얘도 정보를 또 줘야해
// x == y < - > func(x, y) == false && func(y, x) == false; // 이렇게 하자!

int main( )
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

    cout << "원소 50의 개수: " << s.count(50) << endl; // 나중에 multiset이라는 걸 배우면 1을 초과한 값이 나올 수 있다.
    cout << "원소 100의 개수: " << s.count(100) << endl;

    iter = s.find(30); // 30의 반복자를 반환
    if( iter != s.end() )
        cout << *iter <<"가 s에 있다!" << endl;
    else
        cout << "20이 s에 없다!" << endl;
    set<int>::key_compare myComp = s.key_comp(); // 숫자를 배열하는 원칙이 뭐냐.. 그걸 변수로 해서 functor로 뽑아줘!
                                                 // 오름차순이기에 오른쪽이 더 크냐고 물어봄
    cout << "x=" << myComp(50, 30) << endl;
    // 30과 50의 비교 (위에 두 줄로 쓴 것을 한 줄로 표현한 것.)
    cout << (!s.key_comp()(30, 50) && !s.key_comp()(50, 30)) << endl; //다르다(difference)
    // 30과 30의 비교
    cout << (!s.key_comp()(30, 30) && !s.key_comp()(30, 30)) << endl; //같다(equivalence)
}
