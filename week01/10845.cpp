#include<iostream>
#include<queue>
#include<string>
using namespace std;

//queue이용 문제
/*
특징
1. 먼저 들어간 자료가 먼저 나오는 FIFO(First In First Out)구조
2. 큐는 한 쪽 끝은 front로 정하여 삭제 연산만 수행
3. 다른 한 쪽 끝은 rear로 정하여 삽입 연산만 수행

-push X : 정수 X를 넣는 연산
-pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력, 만약 큐가 비어 있으면 -1을 출력
-size : 큐에 들어 있는 정수의 개수를 출력
-empty : 큐가 비어있으면 1, 아니면 0 출력
-front: 큐의 가장 앞에 있는 정수 출력, 큐에 정수 x의 경우 -1출력
-back: 큐의 가장 뒤에 있는 정수 출력, 만약 큐에 정수 x의 경우 -1출력
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

