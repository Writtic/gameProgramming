#include <iostream>
#include <queue>
#include <list>
using namespace std;

void main( )
{
    queue<int, list<int> > q; //����Ʈ�� ����ϴ� queue ����

    q.push(10);
    q.push(20);
    q.push(30);

    while( !q.empty() )
    {
        cout << q.front() << endl;
        q.pop();
    }
}