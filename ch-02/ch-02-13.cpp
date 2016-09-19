#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n) // ���� ������
{
    return 10 <= n &&  n <= 30;
}
void main( )
{
    list<int> lt;
    list<int> lt2;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(10);
    lt.push_back(40);
    lt.push_back(50);
    lt.push_back(10);
    lt.push_back(10);
    
    lt2.push_back(50);
    lt2.push_back(300);
    lt2.push_back(300);
    lt2.push_back(300);
    lt2.push_back(500);
    
    list<int>::iterator iter;    
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    lt.remove(10); // 10 ������ ��带 ��� ����
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
	
    lt.remove_if(Predicate); // �����ڰ� ���� ��� ���Ҹ� �����մϴ�.
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
	
    iter = lt.begin();
    ++iter;
    ++iter; // 30 ������ ��ġ�� ����Ŵ

    lt.splice(iter, lt2); //iter�� ����Ű�� ��ġ�� lt2�� ��� ���Ҹ� �߶� ����

    cout << "lt: ";
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    cout << "lt2: ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
	
    lt.unique();
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;
}
