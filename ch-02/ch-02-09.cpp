#include <iostream>
#include <vector>
using namespace std;

int main( )
{
    vector<int> v(3); //기본값 0으로 초기화된 size가 3인 컨테이너

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    // 확장성 고려
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i) // 메모리가 어마어마하게 커지는 상황을 방지하기 위해 인트 벡터 선언 vector<int>::size_type ���� (unsigned) int ���밡��
        cout << v[i] << " ";
    cout << endl;
    cout <<"size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;

    v.resize(5,10); //지정값 10으로 초기화된 size가 5인 컨테이너
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";
    cout << endl;
    cout <<"[after 5, 10 resized]size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;
    v[0] = 40; // 10에서 40로 수정
    v[1] = 50; // 20에서 50로 수정
    v[2] = 60; // 30에서 60로 수정
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";
    cout << endl;
    cout <<"[after modified] size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;

    v.resize(3); //size가 3인 컨테이너로 축소 capacity는 변화 없음.

    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";
    cout << endl;
    cout <<"[after 3 resized]size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;

    v.clear(); // v를 비운다.
    cout <<"[after cleared] size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;

    if( v.empty() ) // v가 비었는가?
    {
        cout << "v에 원소가 없습니다." << endl;
    }

    vector<int>().swap(v);// 기본 생성자로 만든 vector컨테이너와 v 컨테어너를 swap한다.
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";
    cout << endl;
    cout <<"[after swap] size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << " ";
    cout << endl;
    cout <<"[after push_back] size: "<< v.size() <<"  capacity: " << v.capacity() <<endl;

    vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    v.swap(v2); // v1와 v2를 swap합니다.
    for(vector<int>::size_type i = 0 ; i < v.size() ; ++i)
        cout << v[i] << ", " << v2[i] << endl;
    cout << endl;
}
