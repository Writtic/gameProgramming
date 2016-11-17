// STL.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// 정적 함수 포인터
#include <iostream>
using namespace std;
// 이렇게 프린트 함수가 있으면 따로 프린트 함수를 못 만듬.
void Print(int n)
{
    cout <<"전역 함수: "<< n << endl;
}
// 그래서 따로 그룹핑을 해서 각기 다른 프린트를 사용할 수 있게 됨.
// namespace = grouping
namespace A
{
    void Print(int n)
    {
        cout <<"namespace A 전역 함수: "<< n << endl;
    }
}
class Point
{
public:
    // 클래스 객체가 선언되지 않은 경우에도 호출을 할 수 있음
    // Point p;
    // p.Print(10);
    // 가 아니라
    // Point::Print(10);
    static void Print(int n) // static 배우면 안 됨.
    {
        cout <<"Point 클래스의 정적 멤버 함수: "<< n << endl;
    }
};
int main()
{
  //함수에 대한 포인터라 포인터형으로 선언했음
    void (*pf)(int ); // 정적 함수 포인터 선언. 반환타입:void, 인자:int 특이하니 외우삼..
    // 세개의 꼴은 동일
    // 그러므로 똑같은 포인터로 참고할 수 있음!
    // 포인터 꼴만 잘 선언해주고
    Print( 10 ); // 1. namespace 없는 전역 함수 호출
    A::Print( 10 ); // 2, namespace A의 전역 함수 호출
    // 클래스 인스턴스가 없더라도 함수 호출 가능!
    Point::Print( 10 ); // 3, Point 클래스의 정적 전역 함수 호출
    cout << endl;

    pf = Print;
    pf( 10 );  // 1. 함수 포인터로  namespace 없는 전역 함수 호출
    pf = A::Print;
    pf( 10 );  // 2. 함수 포인터로  namespace A의 전역 함수 호출
    pf = Point::Print;
    pf( 10 );  // 3. 함수 포인터로  Point 클래스의 정적 전역 함수 호출
    // 포인터를 써줘야 되는거 아냐?
    // 엄밀히 말하면 아래가 맞음.
    // 근데 보기가 더러우니까 위와 같은 느낌으로 써도 됨.
	  //(*pf)(10); // 잘됨 - 논쟁이 있음.
    // 고지식한 애들은 *pf 만 인정함. 문법 자체로 보면 pf는 모순이니까!
    int n = 10;
    int *pn = &n; //*pn 이 하나의 변수명이 되므로
    *pn = 3;
    int t = *pn;
    // int k = pn; // 이게 말이 안 됨. 근데 함수 포인터에선 됨.
}
