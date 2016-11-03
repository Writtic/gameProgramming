// Puzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
class State {
private:
	int _i; // zero position
	int _f; // f value
	int num[9];
public:
	int _parent;
	State() {
		for (int i = 0; i < 9; i++)
			num[i] = i;
		_i = 0;
		_f = 9;
		_parent = -1;
	};
	State(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9) {
		num[0] = x1; num[1] = x2; num[2] = x3; num[3] = x4; num[4] = x5; num[5] = x6; num[6] = x7; num[7] = x8; num[8] = x9;
		for (int i = 0; i < 9; i++) {
			if (num[i] == 0)
				_i = i;
		}
		_f = -1;
		_parent = -1;
	}
	void Print() {
		printf("%d %d %d\n", num[0], num[1], num[2]);
		printf("%d %d %d\n", num[3], num[4], num[5]);
		printf("%d %d %d\n\n", num[6], num[7], num[8]);
	}
	// 1,2,3,4,5,6,7,8,0 �������� ����� ���� 1���� �߰���
	int CalcF() {
		_f = 0;
		for (int i = 0; i < 8; i++) {
			if (num[i] != i + 1) _f++;
		}
		if (num[8] != 0) _f++;
		return _f;
	}
	// �� ���� ���� ������ �������� �Ǵ�
	bool IsSame(const State &s) const {
		for (int i = 0; i < 9; i++) {
			if (num[i] != s.num[i])
				return false;
		}
		return true;
	}
	// �̵�
	bool UP(State &res) {
		if (_i <= 2) return false;
		res = *this;
		res.num[_i] = res.num[_i - 3];
		res.num[_i - 3] = 0;
		res._i = _i - 3;
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
// list�� �̹� ������ ���°� �����ϴ��� �˻�
bool IsInList(const State &s, const std::list<State> &list)
{
	for (std::list<State>::const_iterator it = list.begin(); it != list.end(); ++it) {
		if( s.IsSame(*it) == true)
			return true;
	}
	return false;
}
// vector�� �̹� ������ ���°� �����ϴ��� �˻�
bool IsInList(const State &s, const std::vector<State> &list)
{
	for (std::vector<State>::const_iterator it = list.begin(); it != list.end(); ++it) {
		if (s.IsSame(*it) == true)
			return true;
	}
	return false;
}
// list�� ����� ���� �� ���� f���� ���� ���¸� ã�� return
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
int _tmain(int argc, _TCHAR* argv[])
{
	// �ʱ� ����
	State current(4, 1, 3, 0, 2, 6, 7, 5, 8);
	//State current(4, 1, 3, 2, 6, 0, 7, 5, 8);
	//State current(1, 4, 3, 0, 2, 6, 7, 5, 8);
	current.Print();

	// OPEN, CLOSE�� �����ϰ�, �ʱ� ���´� ���䰡 �������� CLOSE�� �ִ´�.
	std::list<State> OPEN;
	std::vector<State> CLOSE;
	CLOSE.push_back(current);

	while (true)
	{
		// ������ �� �ִ� �� �������� ������ ����, ���� ���¸� ����
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
			// ��� �κ��̶� �̵��� �Ұ����ϸ� ����
			if (isPossible == false)
				continue;

			// �̵��� ���°� �����̸� ���
			if (next.CalcF() == 0) {
				printf("found!\n");
				next.Print();
				int parent = CLOSE.size() - 1;
				while (parent != -1) {
					//CLOSE[parent].Print();
					parent = CLOSE[parent]._parent;
				}
				exit(0);
			}

			// �̵��� ���°� ������ ������� �����̸� ����
			if (IsInList(next, OPEN) == true)
				continue;
			if (IsInList(next, CLOSE) == true)
				continue;

			// ���� ���� ���´� ���� ���¹�ȣ�� �θ�� ���
			int current_id = CLOSE.size() - 1;
			next._parent = current_id;
			// ���� ���� ���¸� OPEN�� �߰�
			OPEN.push_back(next);
		}
		//���� ��Ȳ ���
		//printf("open = %d, close = %d\n", OPEN.size(), CLOSE.size());

		// ���� OPEN�� ��������� ���̻� ���� ���°� �����Ƿ�, ���з� ����
		if (OPEN.size() == 0) {
			printf("cannot find\n");
			exit(0);
		}
		// OPEN �Ҽ��� ���� ����� ���¸� ����
		std::list<State>::iterator minState = GetMinState(OPEN);
		
		// ���� ����� ���¸� ���� ���·� �ϰ�, OPEN���� ����� CLOSE�� �߰�
		current = *minState;
		//printf("current node\n");
		//current.Print();
		OPEN.erase(minState);
		CLOSE.push_back(current);
	}
	return 0;
}
