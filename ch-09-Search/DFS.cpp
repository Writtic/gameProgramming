// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <stack>
#include <iostream>
using namespace std;

class State {
public:
	int x, y; // 4L, 3L
public:
	State() { x=0; y=0; };
	State(int _x, int _y) { x=_x; y=_y; };
	void Print() {
		std::cout << x << " , " <<  y << endl;
	}
	bool IsGoal() { return (x==2) && (y==0) ; }

	void Fill4() { x=4;	};
	void Empty4() { x=0; };
	void Fill3() { y=3; };
	void Empty3() { y=0; };
	void Move4to3() {
		// 3리터 물통에 물의 여분이 얼마만큼 남았지?
		int move = 3-y; // y=1 -> move=2
		// 실제 물통과 비교해서 더 적은 양을 옮길 수 있음.
		move = __min(x, move); // x=1
		x -= move;
		y += move;
	}
	void Move3to4() {
		int move = 4-x;
		move= __min(y, move);
		x += move;
		y -= move;
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

int _tmain(int argc, _TCHAR* argv[])
{
	State start(0,0);
	// 생각할 여지가 없는 CLOSE []이미 모든 처리가 끝난 쓰레기 처리장 CLOSE[]
	// 중복된 노드가 있으면 안됨!
	// STL에서 중복된 노드를 방지하기를 원하므로 Pred 함수를 통해 세부적인 중복여부를 체크
	set<State, Pred> CLOSE;
	// 생각할 여지가 남아있는 OPEN
	stack<State> OPEN;
	// 시작부토 고려를 해야하므로 OPEN에 추가
	OPEN.push(start);

	while(true) {
		State current = OPEN.top();
		current.Print();
		// 출력 후 제거
		OPEN.pop();
		// 처리됐으므로 CLOSE에 추가
		CLOSE.insert(current);
		State child[6] = {current, current, current, current, current, current};
		child[0].Empty3();
		child[1].Empty4();
		child[2].Fill3();
		child[3].Fill4();
		child[4].Move3to4();
		child[5].Move4to3();

		for(int i=0; i<6; i++) {
			// 자식이 목표지점에 도달했나?
			if (child[i].IsGoal() ) {
				child[i].Print();
				exit(0);
			}
			//
			set<State, Pred>::iterator iter = CLOSE.find( child[i] );
			if ( CLOSE.end() == iter ) { // 새로 발견된 자식
				OPEN.push(child[i]);
			}
		}
	}
	return 0;
}
