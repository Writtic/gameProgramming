#include <iostream>
using namespace std;
//콜백 (callback)
//////// 서버 /////////////
// 배열의 모든 원소에 반복적인 작업을 하도록 추상화되어 있음
// 정수 배열 begin -> end 까지 함수를 실행
// pf가 뭔지는 모르겠는데 받아서 실행은 해줄겡
void For_each(int *begin, int *end, void (*pf)(int ) )
{
    while( begin != end )
    {
        pf( *begin++ ); // 클라이언트 함수 호출(콜백)
    }
}
/////// 클라이언트 ///////// 건널 수 없는 4차원의 벽이 있음
void Print1(int n)  // 공백을 이용하여 원소를 출력
{
    cout << n <<' ';
}
void Print2(int n) // 각 원소를 제곱하여 출력
{
    cout << n*n <<" ";
}
void Print3(int n) // 문자열과 endl을 이용하여 원소를 출력 (멋지게 장식)
{
    cout <<"정수 : "<< n <<endl;
}
int main( )
{
    int arr[5] = {10, 20, 30, 40, 50};
    // Print 함수를 호출하는 애는 누구? -> 서버
    // 함수를 만든건 클라이언트
    // 나는 함수를 만들고, 실행은 다른놈이 실행해주는 것!
    // 키보드 콜백, OpenGL 콜백 -> 내가 만든 함수 호출해줘~! 함수이름 던짐
    // 이럴 때 함수 포인터가 잘 쓰임
    For_each(arr, arr+5, Print1); // Print1() 콜백 함수의 주소를 전달
    cout << endl << endl;
    For_each(arr, arr+5, Print2); // Print2() 콜백 함수의 주소를 전달
    cout << endl << endl;
    For_each(arr, arr+5, Print3); // Print3() 콜백 함수의 주소를 전달
}
