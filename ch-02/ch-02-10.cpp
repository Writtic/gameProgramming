#include <iostream>
#include <vector>
using namespace std;

int main( )
{
    // 다음의 출력결과를 서술하시오.
    vector<int> v;
    v.assign(5, 3); // 5개의 원소값을 3으로 할당
    cout << "size : " << v.size() <<", capacity : " << v.capacity() << endl;
    for(vector<int>::iterator iter = v.begin(); iter != v.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << v[0] <<", " << v.front() << endl; // 첫 번째 원소
    cout << v[4] <<", " << v.back() << endl; // 마지막 원소

    // 함수에 대입을 한다고...? ㅎㅎ
    // 함수 오퍼레이팅이 주소값을 참조하기 때문에 가능
    v.front() = 10; // 첫 번째 원소를 10으로
    v.back() = 50; // 마지막 원소를 50으로
    for(vector<int>::iterator iter = v.begin(); iter != v.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    v[1] = 20; //범위 점검 없는 0 index 원소의 참조
    v[3] = 40; //범위 점검 없는 4 index 원소의 참조
    for(vector<int>::iterator iter = v.begin(); iter != v.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;
    // 범위 점검을 해서 안전한 값만 전달해줌.
    // 불합리한 대입을 막아줌; 대신 성능이 느림(매번 대입마다 벡터 크기를 점검하므로)
    v.at(0) = 100; //범위 점검 있는 0 index 원소의 참조 v[0] = 100
    v.at(4) = 500; //범위 점검 있는 4 index 원소의 참조 v[4] = 500
    for(vector<int>::iterator iter = v.begin(); iter != v.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    try
    {
        cout << v.at(0) << endl;
        cout << v.at(6) << endl; //throw out_of_range 예외 발생
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
    // const에 관하여
    // 1. 값이 바뀌냐 안 바뀌냐
    // 2. 주소가 바뀌냐 안 바뀌냐
    vector<int>::iterator iter=v.begin(); //다음 원소 이동 가능, 원소 변경 가능
    vector<int>::const_iterator citer = v.begin(); //다음 원소 이동 가능, 원소 변경 불가 (실용적, 자주 쓰임)
    const vector<int>::iterator iter_const = v.begin(); //다음 원소 이동 불가, 원소 변경 가능
    const vector<int>::const_iterator citer_const = v.begin(); //다음 원소 이동 불가, 원소
		// 변경 불가
    vector<int>::reverse_iterator riter; //역방향 반복자

    cout << *iter << endl; //가리키는 원소의 참조
    cout << *citer << endl; //가리키는 원소의 상수 참조
    cout << *iter_const << endl; //iter_const는 p_const처럼 동작함
    cout << *citer_const << endl; //citer_const는 cp_const처럼 동작함.

    iter += 3; // +3한 위치의 원소를 가리킨다.
    cout << *iter << endl;

    iter -= 2; // -2한 위치의 원소를 가리킨다.
    cout << *iter << endl;

	  //iter_const += 3; // 포인터 주소 변경 불가로 컴파일 에러

    cout << *++iter << endl; //다음 원소로 이동한 원소의 참조
    cout << *++citer << endl; //다음 원소로 이동한 원소의 상수 참조

    *iter = 100;  // 일반 반복자는 가리키는 원소를 변경할 수 있음.
    //*citer = 100; // 상수 반복자는 가리키는 원소를 변경할 수 없음.
                    // (컴파일 에러, 속에 들어있는 값을 변경할 수 없음)
    // rbegin and rend
    for( riter = v.rbegin(); riter != v.rend() ; ++riter)
        cout << *riter << " ";
    cout << endl;
}
