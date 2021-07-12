#include<iostream>
#include<deque>
#include<string>
using namespace std;

//deque이용 문제
/*
vector의 단점 보완 위해 만들어진 container로 배열기반 구조
ㄴ> 여러개의 메모리 블록을 할당, 하나의 블록처럼 여기는 기능 제공
메모리 부족할 때 마다 일정한 크기의 새로은 메모리 블록을 할당(이전 원소 복사 x)
*/

int main(void) {
	int N, in;
	string command;
	deque<int> d;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push_front") {
			cin >> in;
			d.push_front(in);
		}
		else if (command == "push_back") {
			cin >> in;
			d.push_back(in);
		}
		else if (command == "pop_front") {
			if (d.size() != 0) {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (command == "pop_back") {
			if (d.size() != 0) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (command == "size") {
			cout << d.size() << '\n';
		}
		else if (command == "empty") {
			cout << d.empty() << '\n';
		}
		else if (command == "front") {
			if (d.size() != 0)
				cout << d.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (command == "back") {
			if (d.size() != 0)
				cout << d.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}

	return 0;
}