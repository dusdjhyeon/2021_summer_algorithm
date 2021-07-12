#include<iostream>
#include<deque>
#include<string>
using namespace std;

//deque�̿� ����
/*
vector�� ���� ���� ���� ������� container�� �迭��� ����
��> �������� �޸� ����� �Ҵ�, �ϳ��� ���ó�� ����� ��� ����
�޸� ������ �� ���� ������ ũ���� ������ �޸� ����� �Ҵ�(���� ���� ���� x)
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