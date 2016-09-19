#include <iostream>
#include <set>
using namespace std;

void main( )
{
    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;
    for( iter = s.begin() ; iter != s.end() ; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "���� 50�� ����: " << s.count(50) << endl;
    cout << "���� 100�� ����: " << s.count(100) << endl;
	
    iter = s.find(30); // 30�� �ݺ��ڸ� ��ȯ
    if( iter != s.end() )
        cout << *iter <<"�� s�� �ִ�!" << endl;
    else
        cout << "20�� s�� ����!" << endl;
	
    // 30�� 50�� ��
    cout << (!s.key_comp()(30, 50) && !s.key_comp()(50,30)) << endl; //�ٸ���
    // 30�� 30�� ��
    cout << (!s.key_comp()(30, 30) && !s.key_comp()(30,30)) << endl; //����(equivalence)
}
