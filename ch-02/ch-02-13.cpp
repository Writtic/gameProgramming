#include <iostream>
#include <list>
using namespace std;
struct Pred{
  bool operator() (int n) {
    return 10 <= n && n <= 30;
  }
};
bool Predicate(int n) // 단항 조건자
{
    return 10 <= n &&  n <= 30;
}
int main( )
{
    list<int> lt;
    list<int> lt2;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(10);
    lt.push_back(40);
    lt.push_back(60);
    lt.push_back(10);
    lt.push_back(10);

    lt2.push_back(50);
    lt2.push_back(300);
    lt2.push_back(300);
    lt2.push_back(300);
    lt2.push_back(500);

    list<int>::iterator iter;
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    lt.remove(10); // 10 원소의 노드를 모두 제거
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    // lt.remove_if(Predicate); // 조건자(함수도 가능)가 참인 모든 원소를 제거합니다.
    lt.remove_if(Pred());
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    iter = lt.begin();
    ++iter; // 60 원소의 위치를 가리킴

    lt.splice(iter, lt2); //iter가 가리키는 위치에 lt2의 모든 원소를 잘라 붙임

    cout << "lt: ";
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    cout << "lt2: ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    lt.unique();
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
}
