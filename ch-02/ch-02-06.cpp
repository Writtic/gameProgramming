#include <iostream>
#include <vector>
using namespace std;

int main( )
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator normal_iter= v.begin()+3;//40 원소를 가리키는 정방향 반복자
    vector<int>::reverse_iterator reverse_iter(normal_iter);// normal_iter의 역방향 반복자

    // 살짝 햇갈릴 수 있는 것은
    // reverse_iter의 begin()은 기존 end()의 주소 앞에 존재
    // end()도 마찬가지
    // 그래서 내부적으로는 한칸씩 앞으로 주소가 밀림
    // 우리는 그 사실을 몰라도 됨.
    // 일반 iter는 40인데
    // reverse_iter는 30을 가르키게 됨.
    cout << "정방향 반복자의 값: " << *normal_iter << endl;
    cout << "역방향 반복자의 값: " << *reverse_iter << endl;
    cout << endl;

    for(vector<int>::iterator iter= v.begin(); iter != normal_iter ; ++iter)
        cout << *iter << " "; //정방향 출력
    cout << endl;

    for(vector<int>::reverse_iterator riter= reverse_iter; riter != v.rend() ; ++riter)
        cout << *riter << " "; //역방향 출력
    cout << endl;
}
