#include <math.h>
#include <set>
#include <stack>
#include <iostream>
#include <algorithm>
// #include "tchar.h"
using namespace std;

class State {
	static const int sx=2, sy=3;
	static const int ex=6, ey=3;
public:
	int x, y;
	int g,h;
	int f; // cost = g + h;
	int px, py; // 부모의 x,y좌표;
public:
	State() { x=0; y=0; };
	State(int _x, int _y) { x=_x; y=_y; };
	void Print() {
		std::cout << x << " , " <<  y << endl;
	}
	bool IsStart() { return (x==sx) && (y==sy) ; }
	bool IsGoal() { return (x==ex) && (y==ey) ; }

	void Move(int dx, int dy) {
		px = x; py = y; // 어디에서 움직였는지 이전지점을 저장
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
int main()
{
	// 초기 지도 설정
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

	// 출발지점과 상태 초기화
	State start(2,3);
	set<State, Pred> CLOSE;
	set<State, FVal> OPEN;
	OPEN.insert(start);
	// 길잧기 시작
	while(true) {
		// Open 중에서 우수한 지점 선택
		// set은 내부적으로 정렬이 되어있기 때문에 가장 첫번째 것을 뽑으면
		// 이상적인 자식노드가 됨. (STL을 통해 편리하게 처리)
		set<State,FVal>::iterator iter= OPEN.begin();
		State current = *iter;
		current.Print();
		OPEN.erase(iter);
		CLOSE.insert(current);
		// 현재 지점에서 어느 방향으로 진행할 지 결정
		for(int y=-1; y<=1; y++) {
			for(int x=-1; x<=1; x++) {
				// 자기자신
				if(x==0 && y==0) continue;
				unsigned char mapinfo = map[current.y + y] [current.x + x];
				// 벽
				if( mapinfo == WALL) continue;
				// 물
				if( mapinfo == WATER) continue;

				State child = current;
				child.Move(x,y);
				if(child.IsGoal()) { // 목표에 도달한 경우
					cout << "경로 출력" << endl;
					child.Print();

					set<State, Pred>::iterator path_iter = CLOSE.find(current);
					// 경로 출력
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

				// 이미 방문한 경로는 무시
				if ( CLOSE.end() != CLOSE.find( child ) )
					continue;

				// 기존 OPEN에 있는 경로인지 확인
				PosEqual pos(child.x, child.y);
				// find는 x,y 좌표만 비교
				set<State, FVal>::iterator find_iter = find_if(OPEN.begin(), OPEN.end(), pos);

				// 기존에 없던 지점이면 추가
				if( find_iter == OPEN.end()) {
					OPEN.insert(child);
				} else { // 기존에 있던 지점이면 현재 경로가 더 좋은 지름길인지 확인
					if(find_iter->f  >  child.f) { // 더 좋은 길 발견
						OPEN.erase(find_iter);
						OPEN.insert(child);
					}
				}

			}
		}
	}
	return 0;
}
