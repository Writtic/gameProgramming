#include <iostream>
#include <string>
using namespace std;

// 특수화 클래스 템플릿
// 클래스 템플릿의 경우에도 특수화가 가능
template<typename T>
class ObjectInfo {
  T data;
public:

  ObjectInfo(const T& d) : data(d) {}

  void Print()
  {
    //typeid 라는 교묘한 함수를 이용해서
    cout << "타입 : " << typeid(data).name() << endl;
    cout << "크기 : " << sizeof(data) << endl;
    cout << "값 : " << data << endl;
    cout << endl;
  }
};
/*
특수화 클래스 템플릿을 안쓰면... 이렇게 뜸
타입 : NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
크기 : 24
값 : Hello!
*/
template<> // T를 string으로 특수화(클래스 템플릿 특수화)
class ObjectInfo<string>{
  string data;
public:
  ObjectInfo(const string& d) : data(d) {}
  void Print()
  {
    // cout <<"타입 : "<< typeid(data).name() << endl;
    cout << "타입 : " << "string" << endl;        // 타입 정보 수정
    // cout <<"크기 : "<< sizeof(data) << endl;
    cout << "문자열 길이 : " << data.size() << endl; // 길이 정보 수정
    cout << "값 : " << data << endl;
    cout << endl;
  }
};

int main()
{
  ObjectInfo<int> d1(10);
  d1.Print(); // 객체 정보 출력
  ObjectInfo<double> d2(5.5);
  d2.Print(); // 객체 정보 출력
  ObjectInfo<string> d3("Hello!");
  d3.Print(); // 객체 정보 출력
}
