#include <iostream>
#include <list>
using namespace std;
// 한번 해보시길...
// 희안하거나 그런건 없어용

int main( )
{
    list<int> lt1;
    list<int> lt2;

    lt1.push_back(20);
    lt1.push_back(10);
    lt1.push_back(50);
    lt1.push_back(30);
    lt1.push_back(40);

    lt2.push_back(25);
    lt2.push_back(35);
    lt2.push_back(60);


    list<int>::iterator iter;
    cout << "lt1: ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    cout << "lt2: ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter << ' ';
    cout << endl << "===============" << endl;

    lt1.sort( ); // 오름차순( less, < 연산) 정렬
    cout << "lt1: ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << ' ';
    cout << endl << "===============" << endl;
    lt1.merge(lt2); // lt2를 lt1으로 합병 정렬합니다. 정렬 기준은 less
                    // lt2는 merge 후 텅텅 비게 된다. 원본이 사라짐!


    cout << "lt1: ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    cout << "lt2: ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
}
