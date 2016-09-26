#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back( 10 );
    dq.push_back( 20 );
    dq.push_back( 30 );
    dq.push_back( 40 );
    dq.push_back( 50 );

    for(deque<int>::size_type i = 0 ; i < dq.size() ; ++i)
        cout << dq[i] << " ";
    cout << endl;

    dq.push_front( 100 ); // 앞쪽에 추가합니다.
    dq.push_front( 200 );
    for(deque<int>::size_type i = 0 ; i < dq.size() ; ++i)
        cout << dq[i] << " ";
    cout << endl;
}

// 연구(ch-02-12): vector에는 v.push_front(100)가 없는 대신 v.insert( v.begin(), 100 )을 사용할 수 있다.
//                push_front가 없는 이유는?
// insert함수로 특정위치에 집어넣는 함수가 있긴 함.
// deque는 push_front가 자연스럽게 구현됨. 벡터는 아니다.
// vector는 맨 앞에 삽입시 그 뒤 값들을 한 칸식 뒤로 밀어야됨(고비용). 그래서 일종의 주의를 주는 것.
// deque는
//        [  ,   ,   ,   , 60]<-back
// front->[10, 20, 30, 40, 50]

// dq[3] 메모리 값으로 나눠서 나머지 값으로 인덱스를 참조
// 진짜 배열만큼 빠르진 않겠지만 벡터보다 빠름.
