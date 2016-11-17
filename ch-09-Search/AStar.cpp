// Puzzle.cpp : Defines the entry point for the console application.

#include <list>
#include <vector>
static int goal[9]={3,0,4,0,0,1,0,2};
class State {
private:
	bool _i;
	int white[2];
	int black[2];
	int _g, _h;
	int _f; // cost = g + h;
	int num[9];
public:
	int _parent;
	State() {
		int temp[9]={3,0,4,0,0,0,1,0,2};
		for (int i=0; i < 9; i++) {
			num[i] = temp[i];
		}
		white[0] = 6;
		white[1] = 8;
		black[0] = 0;
		black[1] = 2;
		// memcpy(num, temp, 9*sizeof(int));
		_i = true;
		_g = -1;
		_h = -1;
		_f = 9;
		_parent = -1;
	};
	State(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9) {
		num[0] = x1; num[1] = x2; num[2] = x3; num[3] = x4; num[4] = x5; num[5] = x6; num[6] = x7; num[7] = x8; num[8] = x9;
		// int temp[9]={3,0,4,0,0,1,0,2};
		// memcpy(goal, temp, 9*sizeof(int));

		for (int i = 0; i < 9; i++) {
			switch (num[i]) {
			case 1:
				white[0] = i; 	break;
			case 2:
				white[1] = i; 	break;
			case 3:
				black[0] = i; 	break;
			case 4:
				black[1] = i; 	break;
			}
		}

		_i = true;
		_g = -1;
		_h = -1;
		_f = -1;
		_parent = -1;
	}
	void Print() {
		for (int i = 0; i < 9; i++) {
			char temp;
			switch (num[i]) {
			case 0:
				temp = '.'; 	break;
			case 1:
				temp = 'O'; 	break;
			case 2:
				temp = 'O'; 	break;
			case 3:
				temp = 'X'; 	break;
			case 4:
				temp = 'X'; 	break;
			}
			printf("%c ", temp);
			if ((i % 3) == 2)
				printf("\n");
		}
	}
	// 1,2,3,4,5,6,7,8,0 순서에서 벗어날때 마다 1점씩 추가됨
	int CalcF() {
		// 평가함수
		_f = 0;
		for (int i = 0; i < 9; i++) {
			if (goal[i] != num[i]) _f++;
		}
		return _f;
	}
	// 두 개 상태의 숫자 순서가 동일한지 판단
	bool IsSame(const State &s) const {
		for (int i = 0; i < 9; i++) {
			if (num[i] != s.num[i])
				return false;
		}
		return true;
	}
	// 이동
	bool MOVE1(State &res) {
		if (_i) {
			if ((res.white[0] % 2) == 1)
				
			_i = false;
		} else {

			_i = true;
		}
		res = *this;
		res.num[_i] = res.num[_i - 3];
		res.num[_i - 3] = 0;
		return true;
	}
	bool DOWN(State &res) {
		if (_i >= 6) return false;
		res = *this;
		res.num[_i] = res.num[_i + 3];
		res.num[_i + 3] = 0;
		res._i = _i + 3;
		return true;
	}
	bool LEFT(State &res) {
		if (_i % 3 == 0) return false;
		res = *this;
		res.num[_i] = res.num[_i - 1];
		res.num[_i - 1] = 0;
		res._i = _i - 1;
		return true;
	}
	bool RIGHT(State &res) {
		if (_i % 3 == 2) return false;
		res = *this;
		res.num[_i] = res.num[_i + 1];
		res.num[_i + 1] = 0;
		res._i = _i + 1;
		return true;
	}
};
// list에 이미 동일한 상태가 존재하는지 검사
bool IsInList(const State &s, const std::list<State> &list)
{
	for (std::list<State>::const_iterator it = list.begin(); it != list.end(); ++it) {
		if( s.IsSame(*it) == true)
			return true;
	}
	return false;
}
// vector에 이미 동일한 상태가 존재하는지 검사
bool IsInList(const State &s, const std::vector<State> &list)
{
	for (std::vector<State>::const_iterator it = list.begin(); it != list.end(); ++it) {
		if (s.IsSame(*it) == true)
			return true;
	}
	return false;
}
// list에 저장된 상태 중 f값이 가장 작은 상태를 찾아 return
std::list<State>::iterator GetMinState(std::list<State> &list)
{
	std::list<State>::iterator minState = list.begin();
	int minF = minState->CalcF();
	for (std::list<State>::iterator it = list.begin(); it != list.end(); ++it) {
		if (it->CalcF() < minF) {
			minState = it;
			minF = it->CalcF();
		}
	}
	return minState;
}
int main()
{
	// 초기 상태
	State current(1, 0, 2, 0, 0, 0, 3, 0, 4);
	//State current(4, 1, 3, 2, 6, 0, 7, 5, 8);
	//State current(1, 4, 3, 0, 2, 6, 7, 5, 8);
	current.Print();

	// OPEN, CLOSE를 생성하고, 초기 상태는 검토가 끝낫으니 CLOSE에 넣는다.
	std::list<State> OPEN;
	std::vector<State> CLOSE;
	CLOSE.push_back(current);

	while (true)
	{
		// 움직일 수 있는 네 방향으로 움직여 보고, 다음 상태를 생성
		for (int i = 0; i < 4; i++) {
			State next;
			bool isPossible = false;
			switch (i) {
			case 0:
				isPossible = current.LEFT(next); 	break;
			case 1:
				isPossible = current.RIGHT(next); 	break;
			case 2:
				isPossible = current.UP(next); 		break;
			case 3:
				isPossible = current.DOWN(next); 	break;
			}
			// 경계 부분이라 이동이 불가능하면 무시
			if (isPossible == false)
				continue;

			// 이동한 상태가 정답이면 출력
			if (next.CalcF() == 0) {
				printf("found!\n");
				next.Print();
				int parent = CLOSE.size() - 1;
				while (parent != -1) {
					// 경로 출력
					// 자식들이 만들어졌을 때 자식들이 부모들을 기억하고 있다면,
					// 최종노드가 나왔을 때 부모를 추적하여 루트노드까지 출력하면
					// 최적의 경로를 알 수 있다.
					CLOSE[parent].Print();
					parent = CLOSE[parent]._parent;
				}
				return 0;
			}

			// 이동한 상태가 기존에 만들어진 상태면 무시
			if (IsInList(next, OPEN) == true)
				continue;
			if (IsInList(next, CLOSE) == true)
				continue;

			// 새로 만든 상태는 형재 상태번호를 부모로 기억
			int current_id = CLOSE.size() - 1;
			next._parent = current_id;
			// 새로 만든 상태를 OPEN집합에 추가
			OPEN.push_back(next);
		}
		//현재 상황 출력
		//printf("open = %d, close = %d\n", OPEN.size(), CLOSE.size());

		// 만약 OPEN이 비어있으면 더이상 꺼낼 상태가 없으므로, 실패로 인정
		if (OPEN.size() == 0) {
			printf("cannot find\n");
			return 0;
		}
		// OPEN 소속중 가장 우수한 상태를 선정
		std::list<State>::iterator minState = GetMinState(OPEN);

		// 가장 우수한 상태를 현재 상태로 하고, OPEN에서 지우고 CLOSE에 추가
		current = *minState;
		//printf("current node\n");
		//current.Print();
		OPEN.erase(minState);
		CLOSE.push_back(current);
	}
	return 0;
}
