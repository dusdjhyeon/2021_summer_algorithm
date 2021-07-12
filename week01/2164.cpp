#include<iostream>
#include<queue>
using namespace std;

//queue 이용 문제(card2)
//1~N까지 순서대로 집어 넣는다 생각하면 pop했을 때 FIFO구조이므로 
//stack이 아닌 queue 이용

int main(void) {
	int N;
	queue<int>card;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		card.push(i);;
	}

	while (card.size() > 1) {
		card.pop();
		card.push(card.front());
		card.pop();
	}

	cout << card.front() << '\n';

	return 0;
}