#include <iostream>
using namespace std;
// 특수화 함수 템플릿
// 교수님은 중요하게 생각하시지 않음.
class Point
{
    int x; int y;
public:
    explicit Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
    void Print( ) const { cout << x <<',' << y << endl; }
};
// 일반화 함수 템플릿
template <typename T>
void Print(T a)
{
    cout << a << endl;
}
// 특수화 함수 템플릿
template < > // 문법이 좀 더럽긴 한데...
// 특수한 자료형에 대해 다른 처리를 함.
// 포인트 자료형에 대해선 이렇게 처리해줘!!!
void Print(Point a) // 명시적인 코드 void Print<Point>(Point a)
{
    cout << "Print 특수화 버전: ";
    a.Print();
}
int main( )
{
    int n = 10;
    double d = 2.5;
    Point pt(2,3);

    Print( n );  // Print<int>( n )    일반화 버전 호출
    Print( d );  // Print<double>( d ) 일반화 버전 호출
    Print( pt ); // Print<Point>( pt ) 특수화 버전 호출
}
