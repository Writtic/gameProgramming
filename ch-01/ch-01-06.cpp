#include <iostream>
using namespace std;
// 스마트 포인터
// 자바의 가비지 콜렉터처럼 자동으로 메모리에서 제거해주는 경우
// 전역변수 : 힙 / new or alloc 힙 부분에서 메모리가 증가.
// 지역변수 : 스택 / declare 스택에서 메모리 관리를 해야 깔끔함.
// A()
// {
//   int x;
//   B();
// }
// B()
// {
//   int y;
//   Class C;
//C.~Class();
// }
// 함수에서 로컬변수로 만든 클래스의 경우 클래스가 종료될 때 소멸자가 호출됨.
// 해당 아이디어로 자동적으로 메모리관리를 할 순 없을까
// [   ]
// [   ]
// [ y ]
// [ x ]

// 고급스러운 방식이라 요즘 대 유행!
// 단점은 스마트 포인터를 모르는 신입사원이 딜리트를 또 해버려서 죽어버림...
class Point
{
    int x;
    int y;
public:
    //_는 그냥...
    Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
    void Print( ) const { cout << x <<',' << y << endl; }
};
// 여기서부터 마법
class PointPtr
{
    // 위에서 만든 클래스의 포인터값을 가지고 있음.
    Point *ptr;
public:
    // 자기 자신이 아닌 다른 클래스의 포인터값으로 맴버변수를 설정
    PointPtr(Point *p):ptr(p) {  } //ptr = p
    ~PointPtr( )
    {
        delete ptr;
    }
    // 자신이 먹고있던 맴버변수 ptr을 리턴
    Point* operator->()const
    {
        return ptr;
    }

    Point& operator*()const
    {
        return *ptr;
    }
};
int main()
{
    Point* p1 = new Point(2,3); //일반 포인터 (힙)
    PointPtr p2 = new Point(5,5); //스마트 포인터
    // PointPtr 은 Print 함수를 가지고 있지 않지만 Point가 가지고 있는 함수를 호출해서 사용
    p1->Print(); //p1->Print() 호출
    p2->Print(); //p2.operator->()->Print() 호출
    cout << endl;

    (*p1).Print(); //(*p1).Print() 호출
    (*p2).Print(); //p1.operator*().Print() 호출

    delete p1; // 소멸자 호출해서 메모리 소거 (정상적인 C++ 구조)
    //p2의 소멸자에서 Point 동적 객체를 자동 메모리 제거합니다.
}
