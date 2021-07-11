#include<iostream>
#include<queue>
#include<string>
using namespace std;

//queue�̿� ����
/*
Ư¡
1. ���� �� �ڷᰡ ���� ������ FIFO(First In First Out)����
2. ť�� �� �� ���� front�� ���Ͽ� ���� ���길 ����
3. �ٸ� �� �� ���� rear�� ���Ͽ� ���� ���길 ����

-push X : ���� X�� �ִ� ����
-pop : ť���� ���� �տ� �ִ� ������ ����, �� ���� ���, ���� ť�� ��� ������ -1�� ���
-size : ť�� ��� �ִ� ������ ������ ���
-empty : ť�� ��������� 1, �ƴϸ� 0 ���
-front: ť�� ���� �տ� �ִ� ���� ���, ť�� ���� x�� ��� -1���
-back: ť�� ���� �ڿ� �ִ� ���� ���, ���� ť�� ���� x�� ��� -1���
*/

int main(void) {
	int N, in;
	string command;
	queue<int> s;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> in;
			s.push(in);
		}
		else if (command == "front") {
			if (!s.empty())
				cout << s.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (command == "back") {
			if (!s.empty())
				cout << s.back() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (command == "size") {
			cout << s.size() << '\n';
		}
		else if (command == "empty") {
			cout << s.empty() << '\n';
		}
		else if (command == "pop") {
			if (!s.empty()) {
				cout << s.front() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
	}

	return 0;
}

