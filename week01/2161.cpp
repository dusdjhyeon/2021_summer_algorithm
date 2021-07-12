#include<iostream>
#include<queue>
#include<deque>
using namespace std;

//deque와 queue이용 문제
//vector의 단점을 보완한 deque를 통해 queue의 사이즈 만큼 deque 자동 조절

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