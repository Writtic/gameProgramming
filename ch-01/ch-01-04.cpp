#include <iostream>
using namespace std;
// 함수 호출 연산자 오버로딩 (()연산자)
struct FuncObject
{
public:
    // 함수 호출이 일어나면... 이렇게 해줘!
    void operator()( int arg ) const
    {
        cout <<"정수 : " << arg << endl;
    }
    void operator()( int arg1, int arg2 ) const
    {
        cout <<"정수 : " << arg1 << ',' << arg2 << endl;
    }
    void operator()( int arg1, int arg2, int arg3 ) const
    {
        cout <<"정수 : " << arg1 << ',' << arg2 << ',' << arg3 << endl;
    }
};

int main( )
{
    FuncObject print; //= FuncObject();
    print(10); //객체 생성 후 호출 시작(암시적)
    print(10,20);
    print(10,20,30);
    cout << endl;
    print.operator()(10); //객체 생성 후 호출 시작(명시적) 위 문법과 완전히 동일.
    print.operator()(10,20);
    print.operator()(10,20,30);
    cout << endl;

    FuncObject()(10); //임시 객체로 호출(암시적) <- 신기방기하니 잘 봐둬라. 어려운 문법으로 짤리기 어렵게 하는 테크닉도 ... 짜를테면 짤라봐라...
    FuncObject()(10,20);
    FuncObject()(10,20,30);
    cout << endl;

    FuncObject().operator()(10); //객체 생성 후 호출 시작(명시적)
    FuncObject().operator()(10,20);
    FuncObject().operator()(10,20,30);
}
