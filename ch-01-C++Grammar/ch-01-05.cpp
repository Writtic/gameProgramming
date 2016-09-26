#include <iostream>
using namespace std;

class Array {
  int *arr;
  int  size;
  int  capacity;

public:
  // 생성자
  Array(int cap = 100) : arr(0), size(0), capacity(cap)
  {
    // 메인함수에서 cap = 10
    // 10개 짜리 배열 생성
    arr = new int[capacity];
  }

  ~Array()
  {
    delete[] arr;
  }

  void Add(int data)
  {
    // 현제 메모리 한계가 허용하는 한 현제 위치에 데이터를 넣고, 사이즈 증가
    if (size < capacity) arr[size++] = data;
  }

  int Size() const
  {
    return size;
  }
  // 다른 공간에 메모리를 할당받아 복사본을 만든 후
  // 복사본을 수정해서 리턴
  // int operator[](int idx) const
  // {
  //   return arr[idx];
  // }
  // 메모리 공간을 참조하는 주소를 찾아가
  // 원본을 수정해서 리턴
  int& operator[](int idx) const
  {
    return arr[idx];
  }
};

int main()
{
  Array ar(10);

  ar.Add(10);
  ar.Add(20);
  ar.Add(30);
  cout << ar.Size() << endl;
  ar[1] = 25;
  // 배열이 아니지만 배열처럼 사용할 수 있게된 좋은 코드
  // 한번 고생해서 array 함수들을 만들면 main에서 두고두고 편하게 쓸 수 있다.
  for (int i = 0; i < ar.Size(); i++) cout << ar[i] << endl;  // ar.operator[](i)
                                                              // 와 같습니다.
  for (int i = 0; i < ar.Size(); i++) cout << ar.operator[](i) << endl;


}
