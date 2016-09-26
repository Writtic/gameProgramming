#include <iostream>
#include <list>
using namespace std;
struct Pred{
  bool operator() (int n) {
    return 10 <= n && n <= 30;
  }
};
struct Pred2{
  int ddd;
  bool operator() (int n) {
    return 10 <= n && n <= ddd;
  }
};
struct Pred3{
  int max;
  Pred3(int m) {
    max = m;
  }
  bool operator() (int n) {
    return 10 <= n && n <= max;
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
    lt.remove_if(Pred()); // Pred()의 괄호가 operator()의 괄호와 같지 않다.
                          // Pred()의 괄호는 생성자의 괄호다!
    struct Pred ttt = Pred(); // <- 여기의 생성자, functor는 좀 특이하군요!
    lt.remove_if(ttt);

    struct Pred2 ttt2; // 이렇게도 가능
    ttt2.ddd = 100;
    lt.remove_if(ttt2);

    struct Pred3 ttt3 = Pred3(100);
    lt.remove_if(ttt3);

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
