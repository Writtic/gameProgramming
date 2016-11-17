#include <iostream>
using namespace std;
// 단항, 이항 연산자 오버로딩
class Point
{
    int x;
    int y;
public:
    Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
    void Print( )const { cout << x <<',' << y << endl; }
    // & 복사본이 아닌 원본
    Point& operator++ ( ) // 전위 ++ : 나 자신을 리턴
    {
        ++x;
        ++y;
        return *this; //내가 바뀐거니까 바뀐 나를 리턴
    }
    Point operator++(int ) // 후위 ++ : 편법으로 위의 전위연산자와 구분, 뭔가 변수명을 써도 되긴 하는데 의미없음.
    {
        // 자기자신을 변경하지 않고 임시변수를 만들어서 리턴
        Point pt(x, y);
        // 자기자신은 플러스
        x++;
        y++;
        // 임시변수 리턴으로 연산시에는 플러스 되지 않은 기존 값을 사용
        return pt;
    }
    bool operator== (const Point& arg) const
    {
      return x==arg.x && y==arg.y ? true : false;
    }
    bool operator!= (const Point& arg) const
    {
      return !(*this == arg);
    }

};
int main( )
{
    Point p1(2,3), p2(5,5), p3(2,3);
    Point result;

    //result = ++p1; // p1.operator++(); 와 같습니다.
    result = ++(++p1); // &를 떼고 실행하면 4,5가 3,4로 바뀜.
    p1.Print();
    result.Print();
    result = p2++; // p2.operator++(0); 와 같습니다. 그냥 이렇게 약속을 함.
    p2.Print();
    result.Print();

    if( p1 != p2 )  // p1.operator!= (p2) 와 같습니다.
      cout << "p1 != p2" << endl;
    if( p1 != p3 )  // p1.operator!= (p3) 와 같습니다.
      cout << "p1 != p3" << endl;
}
// 실습 (ch-01-02): 전위 ++의 리턴형이 참조형인 이유를 result = ++(++p1); 를 실행하여 확인해보자.
// &을 안붙였을 때 임시객체가 생성됨.
// 현제 2,3
// 연산후 3,4
// *this로 Point 리턴 (임시객체가 생성되어서 객체에 복사되어 리턴)
// 임시객체도 3,4
// 그럼 괄호 밖에선 임시객체에 ++을 함

// 후위는 궂이 원본 참조를 하지 않아도 됨.

// 연구 (ch-01-02):  != 의 내부가 == 를 이용하여 정의되는 이유를 생각해보자.
// x!=arg.x || y!=arg.y ? true : false 면 연산자 호출이 더 적지 않냐?
// 성능은 위의 경우가 더 좋음. 컴파일러가 똑똑하면 차이는 없지만.
// !(*this == arg) 는 유지보수가 쉬워짐. 만약에 x만 같은걸로 하자 하면 원본의 방법이 더 좋음.
// 현재는 컴파일러의 성능을 신뢰하기 때문에 원본과 같이 짜는게 좋음.
