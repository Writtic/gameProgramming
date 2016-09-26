#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int n)
{
    cout << n << " ";
}
void main( )
{  
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    v2.push_back(60);
    v2.push_back(70);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
	
    vector<int> v3;
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] <<" ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] <<" ";
    cout << endl;
	
    //���� [v1.being(), v1.end)�� ���� [v2.begin(), v2.begin()+3)�� �� �մϴ�.
    if( equal(v1.begin(), v1.end(), v2.begin()) )
        cout << "�� �������� �����ϴ�." << endl;
	
    for_each(v2.begin(), v2.begin()+3, Print);
    cout << endl;
    for_each(v2.begin(), v2.begin()+6, Print);
    cout << endl;
    //[v.begin(), v.end()) ������ ���� ���
    for_each(v2.begin(), v2.end(), Print);
    cout << endl;

	
    vector<int>::iterator iter;
    iter = search(v2.begin(), v2.end(), v3.begin(), v3.end());
    if( iter != v2.end() )
    {
        // ��ġ�ϴ� ù ��° �������� ù ������ �ݺ��� iter
        cout << "iter : " << *iter << endl;
        cout << "iter-1 : " <<*(iter-1) << endl;
        cout << "iter+1 : " <<*(iter+1) << endl;;   
    }
}