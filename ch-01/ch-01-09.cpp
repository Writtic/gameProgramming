#include <iostream>
using namespace std;

// 멤버 함수 포인터
class Point {
  int x;
  int y;

public:

  // explicit?
  // 두 개의 파라미터에 각각 값을 집어넣음.
  explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

  void f()
  { x++; y++; }
  //변수 수정을 해당 함수에서 할 수 없음. 있는 값 그대로 써야함. 물론 다른 함수에서 수정된 값이 반영되긴 함.
  void Print() const {
    cout << x << ',' << y << endl;
  }

  void PrintInt(int n) {
    cout << "테스트 정수 : " << n << endl;
  }
};
int main()
{
  // Point pt = Point(2, 3); // 얜 아무문제 없음.
  // Point pt = Point(); // 얘는 Point(0, 0) 과 동일
  // Point pt = Point(2); // 첫번째만 초기화

  Point pt(2, 3);
  Point *p = &pt;
  // Point p = pt; 얜 함수 포인터가 아님
  void (Point::*pf1)() const; // 멤버 함수 포인터 선언 (상수 함수, 맴버 변수를 오버라이딩으로 쓰지 못 함)
  // Print 함수의 클래스 Point 주소를 받아와 pf1에 저장
  pf1 = &Point::Print;

  void (Point::*pf2)(int); // 멤버 함수 포인터 선언
  pf2 = &Point::PrintInt;

  pt.Print();
  pt.PrintInt(10);
  cout << endl;

  // pf1();
  // pf2(); 는 왜 안돼?
  // 클레스에 들어있는 함수는 특별하게도 걔네들의 멤버변수를 접근 가능
  // 클레스 변수가 여러개 있으면 그때그때 다르게 따로따로 접근이 가능해야함.
  // 그래서 이렇게만 호출하면 내 멤버변수값이 10인지 20인지 알 수가 없음.
  (pt.*pf1)();   // 객체로 멤버 함수 포인터를 이용한 호출 //pt(2,3)을 통해 멤버변수값을 확인 가능
  (pt.*pf2)(10); // 객체로 멤버 함수 포인터를 이용한 호출
  cout << endl;

  // pt 의 주소를 받아서 p라고 했었징
  // 잘 되는군
  (p->*pf1)();   // 주소로 멤버 함수 포인터를 이용한 호출
  (p->*pf2)(10); // 주소로 멤버 함수 포인터를 이용한 호출
  // 실습 (ch-01-09): 이번 예제에서는 안 됨. 글로벌 변수에서는 붙여도 되고 안 붙여도 됨.
  // (p->pf2)(10);
  // (시험엔 안나옴)

  // 실습 (ch-01-09):
  //Point q = 6;   // 컴파일러는 똑똑해서 얘를 이렇게 Point q = Point(6)시도 해 봄
  // 그럼 프로그래머는 6을 대입했을 때 Point(6, 0)을 허용할지 안할지는... 옳고 그름이 없음.
  // 우리가 정의해야함.
  // 허용하지 않으려면 explicit!
  // 근데 explicit을 안 쓰면 코드가 폭망하는 경우가 생김(위의 경우는 버그로 인식되지 않음, 디버깅 불가)
  // explicit은 암시적 형변환을 못하게 막음.(컴파일시 에러로 인식! 더 책임감을 가지고 짤수밖에 없음!)
}
