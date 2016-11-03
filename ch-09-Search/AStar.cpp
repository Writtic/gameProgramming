#include <math.h>
#include <set>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class State {
	static const int sx=2, sy=3;
	static const int ex=6, ey=3;
public:
	int x, y;
	int g,h;
	int f; // cost = g + h;
	int px, py; // �θ��� x,y��ǥ;
public:
	State() { x=0; y=0; };
	State(int _x, int _y) { x=_x; y=_y; };
	void Print() {
		std::cout << x << " , " <<  y << endl; 
	}
	bool IsStart() { return (x==sx) && (y==sy) ; }
	bool IsGoal() { return (x==ex) && (y==ey) ; }
	
	void Move(int dx, int dy) {
		px = x; py = y; // ��𿡼� ���������� ���������� ����
		x += dx;
		y += dy;
		g += (int)sqrt(dx*dx*100.0 + dy*dy*100.0);
		h = abs(x-ex)*10 + abs(y-ey)*10;
		f = g + h;
	}
};
struct Pred
{
	bool operator ()(State a, State b) {
		if(a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
};

struct FVal
{
	bool operator() (State a, State b) {
		if(a.f == b.f) {
			if(a.x == b.x)
				return a.y < b.y;
			else
				return a.x < b.x;
		} else
			return a.f < b.f;
	}
};

struct PosEqual
{
	int x, y;
	explicit PosEqual(int _x=0, int _y=0) { x=_x; y=_y; };
	bool operator() (State a) {
		return (a.x == x && a.y == y);
	}
};
enum { LAND=0, WATER, START, END, ROAD, WALL=9 };

void PrintMap(unsigned char map[7][9])
{
	for(int i=0; i<7; i++) {
		for(int j=0; j<9; j++) {
			char ch=' ';
			switch(map[i][j]) {
				case LAND: ch='.'; break;
				case WATER: ch='W'; break;
				case WALL:	ch=' '; break;
				case START: ch='S'; break;
				case END: ch='E'; break;
				case ROAD: ch='@'; break;

			}
			printf("%c", ch);
		}
		printf("\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	// �ʱ� ���� ����
	unsigned char map[7][9] = {
		{9,9,9,9,9,9,9,9,9},
		{9,0,0,0,0,0,0,0,9},
		{9,0,0,0,1,0,0,0,9},
		{9,0,2,0,1,0,3,0,9},
		{9,0,0,0,1,0,0,0,9},
		{9,0,0,0,0,0,0,0,9},
		{9,9,9,9,9,9,9,9,9}
	};
	PrintMap(map);

	// ��������� ���� �ʱ�ȭ
	State start(2,3);
	set<State, Pred> CLOSE;
	set<State, FVal> OPEN;
	OPEN.insert(start);
	// ��ã�� ����
	while(true) {
		// Open �߿��� ����� ���� ����
		set<State,FVal>::iterator iter= OPEN.begin();
		State current = *iter;
		current.Print();
		OPEN.erase(iter);
		CLOSE.insert(current);
		// ���� �������� ��� �������� ������ �� ����
		for(int y=-1; y<=1; y++) {
			for(int x=-1; x<=1; x++) {
				if(x==0 && y==0) continue;
				unsigned char mapinfo = map[current.y + y] [current.x + x];
				if( mapinfo == WALL) continue;
				if( mapinfo == WATER) continue;

				State child = current;
				child.Move(x,y);
				if(child.IsGoal()) { // ��ǥ�� ������ ���
					cout << "��� ���" << endl;
					child.Print();

					set<State, Pred>::iterator path_iter = CLOSE.find(current);
					// ��� ���
					State path = *path_iter;
					while(  path.IsStart() == false)  {
						map[path.y][path.x] = ROAD;
						path.Print();
						path = State(path.px, path.py);
						path_iter = CLOSE.find(path);
						path = *path_iter;
					}
					path.Print();
					PrintMap(map);
					exit(0);
				}

				// �̹� �湮�� ��δ� ����			
				if ( CLOSE.end() != CLOSE.find( child ) )
					continue; 

				// ���� OPEN�� �ִ� ������� Ȯ��
				PosEqual pos(child.x, child.y);
				// find�� x,y ��ǥ�� ��
				set<State, FVal>::iterator find_iter = find_if(OPEN.begin(), OPEN.end(), pos);

				// ������ ���� �����̸� �߰�
				if( find_iter == OPEN.end()) { 
					OPEN.insert(child);
				} else { // ������ �ִ� �����̸� ���� ��ΰ� �� ���� ���������� Ȯ��
					if(find_iter->f  >  child.f) { // �� ���� �� �߰�
						OPEN.erase(find_iter);
						OPEN.insert(child);
					}
				}
				
			}
		}
	}
	return 0;
}
