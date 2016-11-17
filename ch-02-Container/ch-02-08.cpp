#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v1;
  vector<int> v2;

  // 사이즈 : 실제 들어간 데이터 크기, 용량 : 들어갈 수 있는 데이터 공간 크기
  // 처음에는 하나씩 늘려가지만, 나중에 데이터양이 많아지만 크게크게 데이터 공간을 늘림.
  // 비효율적! 데이터가 새로 할당될때마다 운영체제와 통신을 해서 할당여부를 확인해야함.
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(10);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(20);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(30);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(40);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(50);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(60);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(70);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(80);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(90);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;
  v1.push_back(100);
  cout << "size: " << v1.size() << "  capacity: " << v1.capacity() << endl;

  for (vector<int>::size_type i = 0; i < v1.size(); ++i) cout << v1[i] << " ";
  cout << endl;

  // 아직 할당하진 않았지만 최대로 할당 가능한 메모리들을 출력
  cout << "Max size: " << v1.max_size() << endl << endl;

  // 8개의 메모리 공간을 할당하고 시작한다.
  v2.reserve(8);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(10);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(20);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(30);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(40);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(50);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(60);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(70);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(80);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;
  v2.push_back(90);
  cout << "size: " << v2.size() << "  capacity: " << v2.capacity() << endl;

  for (vector<int>::size_type i = 0; i < v2.size(); ++i) cout << v2[i] << " ";
  cout << endl;
  cout << "Max size: " << v2.max_size() << endl << endl;
}
