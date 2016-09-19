#include <iostream>

// 함수 객체 (함수자(Functor)라고도 부름, 펑터!)
// 오퍼레이터 오버로딩으로 실행
using namespace std;

//함수호출은 비싼 연산이다.
//함수 메모리에 적재, 변수들도 적재, 연산 수행
/*
inline int func(int a, int b){
  return a+b;
}
int main(){
  // 컴파일러가 똑똑하게 구문 분석을 해서
  // func(3, 4)를 3 + 4로 바꿔버림 : 엄청 빨라짐, 함수호출도 안 함.
  // 하지만 함수 내부의 전체 코드를 그대로 치환해버리기 때문에 전체 코드량이 늘어나서 실행 파일의 크기가 커짐.
  // functor를 쓰면 inline으로 바뀔 확률이 높아짐 << 왜??
  // 컴파일 타임에 소스를 다 분석해서 모든 코드 분석이 끝나야 함.
  // 펑션 포인터를 쓰면 사용자의 입력에 따라 어떤 함수를 호출할지 대입할 수 없게 됨.
  // 펑션 포인터 컴파일 타임에 결정되지 않을 수 있음.
  // 무조건 컴파일타임에 결정이 됨.
  cout << func(3, 4) << endl;
  cout <<
}
*/
// 클래스(객체)인데 함수처럼 동작하네??
struct LessFunctor // 1. 함수 객체 조건자
{
  int operator()(int left, int right) const
  {
    if(left < right) return left;
    else return right;
  }
};
int LessFun(int left, int right) // 2. 함수 조건자: 같은 기능을 하는 함수
{
  if(left < right) return left;
  else return right;
}

int main()
{
  int (*LessPtr)(int,
                  int) = LessFun; // 3. 함수 포인터 조건자 / 정적 함수 포인터 선언.
  LessFunctor lessFunctor; // 변수처럼 등록

  //모두 bool 형식을 반환
  // 1. 함수 객체로 10과 20을 비교 (left, right)
  // 클래스(객체)인데 함수처럼 동작하네??
  // ---- 첫번째 줄, 두번째 줄에 익숙해 지시면됩니다!! ----
  // 확장성
  // 실행 파일의 성능이 좋아질 가능성이 있음 : 인라인 Function이 될 가능성이 높음.
  // 결국 함수 포인터의 기능을 사용하면서 성능을 끌어올리고 싶을 때 사용한다는 말씀인가요?
  // 함수를 변수처럼 사용하면서 (값을 복사할수도 파라미터에 전달, 배열에 쌓아올릴 수 있고)
  cout << lessFunctor(10, 20) << endl; // 깔끔
  cout << LessFunctor()(10, 20) << endl; // 클래스 생성자를 바로 호출해서 lessFunctor 호출 //아! 더럽다

  // 2. 함수로 10과 20을 비교
  cout << LessFun(10, 20) << endl;

  // 3. 함수 포인터로 10과 20을 비교
  cout << LessPtr(10, 20) << endl;
}
