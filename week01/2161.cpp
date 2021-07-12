#include<iostream>
#include<queue>
#include<deque>
using namespace std;

//deque�� queue�̿� ����
//vector�� ������ ������ deque�� ���� queue�� ������ ��ŭ deque �ڵ� ����

int main(void) {
	int N;
	queue<int>card;
	deque<int>trash;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		card.push(i);
	}

	while (card.size() > 1) {
		trash.push_back(card.front());
		card.pop();
		card.push(card.front());
		card.pop();
	}

	while (!trash.empty()) {
		cout << trash.front() << ' ';
		trash.pop_front();
	}

	cout << card.front() << '\n';

	return 0;
}