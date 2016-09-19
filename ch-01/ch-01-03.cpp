#include <iostream>
using namespace std;
// 전역 함수를 이용한 연산자 오버로딩
// 클래스 자체에는 오퍼레이터가 없음.
class Point
{
    // x, y는 기본적으로 private
    int x;
    int y;
public:
    Point(int _x =0 , int _y = 0 ):x(_x),y(_y) { }
    void Print( )const { cout << x <<',' << y << endl; }
    int GetX()const { return x; } // x의 getter
    int GetY()const { return y; } // y의 getter
    // friend 함수는 구조는 더러워지지만... 함수호출 비용이 줄어듬...
    //friend const Point operator- (const Point& argL, const Point& argR);
    // Point operator*(int d) { return Point(x*d, y*d); }
};
// 클래스 외부에 멀쩡한 함수로 오퍼레이터가 선언되어 있음.
const Point operator- (const Point& argL, const Point& argR)
{
    return Point( argL.GetX()-argR.GetX(), argL.GetY()-argR.GetY());
}
const Point operator* (int d, const Point& argR){
  return Point(d * argR.GetX(), d * argR.GetY());
}
// friend 함수를 이용한 방법
// 위는 함수호출로 x, y를 받아옴. 
// 하지만 함수호출도 비용...
//const Point operator- (const Point& argL, const Point& argR)
//{
//    return Point( argL.x-argR.x, argL.y-argR.y );
//}
int main( )
{
    Point p1(2,3), p2(5,5);
    Point p3;

    p3 = p1 - p2;
    p3.Print();

    // Point p4 = p1 * 3;
    // p4.Print();
    Point p4 = 3 * p1; // 클래스 내부에 정의된 오퍼레이터로는 이걸 실행 못함.
    p4.Print();
    // 근데 이런거 만드는것보단
    // p4.MulConst(3); 이런걸로 하면 됨...
}
