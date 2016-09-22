#include <iostream>
#include <queue>
#include <deque>
using namespace std;
// deque Point 구조체 version
struct Point
{
    int x;
    int y;
    Point(int a, int b){
      x = a;
      y = b;
    }
    void Print( ) { cout << x <<',' << y << endl; }
};
struct cmp {
  bool operator()(Point a, Point b) {
    return ((double)((a.x*a.x)+(a.y*a.y)) > (double)((b.x*b.x)+(b.y*b.y)));
  }
};
struct cmp2 {
  bool operator()(Point a, Point b) {
    return ((double)((a.x*a.x)+(a.y*a.y)) < (double)((b.x*b.x)+(b.y*b.y)));
  }
};
int main( )
{
    priority_queue<Point, deque<Point>, cmp> pq1; // 기본컨테이너 vector<Point>, 기본정렬기준 less

    pq1.push(Point(3, 4));
    pq1.push(Point(4, 4));
    pq1.push(Point(1, 4));
    pq1.push(Point(3, 2));
    pq1.push(Point(3, 6));

    cout<<"priority_queue[less]:" <<endl;
    while( !pq1.empty() )
    {
        cout << pq1.top().x << ", " << pq1.top().y << endl;
        pq1.pop();
    }
    cout <<"================" << endl;

    priority_queue<Point, deque<Point>, cmp2 /*functor*/ > pq2;
    pq2.push(Point(3, 4));
    pq2.push(Point(4, 4));
    pq2.push(Point(1, 4));
    pq2.push(Point(3, 2));
    pq2.push(Point(3, 6));

    cout<<"priority_queue[greater]:" <<endl;
    while( !pq2.empty() )
    {
        cout << pq2.top().x << ", " << pq2.top().y << endl;
        pq2.pop();
    }
}
