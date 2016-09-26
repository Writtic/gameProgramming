#include <iostream>
using namespace std;
// 함수 템플릿
// 필요한 타입에 따라 함수가 저절로 만들어짐 (컴파일러가 만들어 줌)
// 단점 : 실행 파일의 크기가 커진다... (그때 그때 바뀔때마다 만들어주니까)
// 디버그가 힘들다.
template <typename T>
void Print1(T a, T b)
{
    cout << a << ", " << b << endl;
}
template <typename T1, typename T2>
void Print2(T1 a, T2 b)	//서로 다른 두개의 매개변수
{
    cout << a << ", " << b << endl;
}
int main( )
{
    Print1(10, 20); // 정수 출력
    Print1(0.123, 1.123); // 실수 출력
    Print1("ABC", "abcde"); //문자열 출력

    Print2(10, 1.5); // 정수, 실수 출력
    Print2("Hello!", 1.5); // 문자열, 실수 출력

    //명시적 타입 지정 후 호출
    Print1<int>(10, 20); // 정수 출력
    Print1<float>(0.123, 1.123); // 실수 출력 // 가만히 냅두면 더블로 인식
    Print1<const char*>("ABC", "abcde"); // 문자열  출력
}
