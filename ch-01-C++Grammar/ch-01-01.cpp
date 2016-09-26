#include <iostream>
using namespace std;
// 연산자 오버로딩
class Point
{
    int x;
    int y;

  public:
    Point(int _x =0 , int _y = 0 ):x(_x),y(_y) { }
    void Print( ) { cout << x <<',' << y << endl; }
    Point operator+(Point arg) //arg 는 구조체처럼 생각해서 포인터를 안씀.
    {
      cout << "operator+()" << endl;
      // this-> 안써도 됨. 왜냐하면 내 x, y 니까!
      Point temp(this->x+arg.x,this->y+arg.y);
      return temp;
    }
    Point operator-(Point arg)
    {
      cout << "operator-()" << endl;
      return Point(x-arg.x, y-arg.y);
    }
};
int main( )
{
Point p1(2,3), p2(5,5);

    //p1+p2; // => p1.operator+( p2 ); 와 같다.
    Point p3 = p1 + p2;
    p3.Print();
    Point p4 = p1 - p2;
    p4.Print();
}
