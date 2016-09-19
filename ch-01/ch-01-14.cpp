#include <iostream>
#include <string> //문자열 string 클래스 헤더
using namespace std;
// 클래스 템플릿
template <typename T> // 클래스 템플릿 Array 정의
class Array
{
    T *buf; // 무슨 자료형인지 모르는 애가 buf 배열로 들어가 있음
    int size;
    int capacity;
public:
    explicit Array(int cap = 100):buf(0), size(0), capacity(cap)
    {
        buf = new T[capacity]; // 가만히 냅두면 100개짜리 배열을 만듬
    }
    ~Array( ) { delete [] buf; }
    void Add( T data)
    {
        buf[size++] = data; // 데이터 복사 혹은 대입, 나의 배열에... 차곡차곡 하나하나 쌓아올림
    }
    T operator[](int idx) const
    {
        return buf[idx]; //대입할 수 없도록 참조형이 아닌 일반형으로 되어있음. 복사본만 불러와 들여다 볼 수만 있음,
    }
    int GetSize() const
    {
        return size;
    }
};
int main( )
{
    Array<int> iarr; //정수(클라이언트가 T 타입 결정) Array 정의
    iarr.Add( 10 );
    iarr.Add( 20 );
    iarr.Add( 30 );

    for( int i = 0 ; i < iarr.GetSize() ; ++i)
        cout << iarr[i] << " ";
    cout << endl;

    Array<double> darr; //실수(클라이언트가 T 타입 결정) Array 정의
    darr.Add( 10.12 );
    darr.Add( 20.12 );
    darr.Add( 30.12 );

    for( int i = 0 ; i < darr.GetSize() ; ++i)
        cout << darr[i] << " ";
    cout << endl;
    //Array<char*> sarr; //얘는 진짜 위험할 수 있음. 포인터 주소 띡 앞에만 따다가 만들면;;; 원본이 바뀌어 버리면 위험위험해
    Array<string> sarr; //문자열(클라이언트가 T 타입 결정) Array 정의
    // string이라고 하는 애는 똑똑한 애임.
    sarr.Add( "abc" );
    sarr.Add( "ABC" );
    sarr.Add( "Hello!" );
    // 문자열을 바로 대입해 쓴다? 좀 위험하지 않나??
    for( int i = 0 ; i < sarr.GetSize() ; ++i)
        cout << sarr[i] << " ";
    cout << endl;
}
