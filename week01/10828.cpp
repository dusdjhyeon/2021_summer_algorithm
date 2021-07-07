#include<iostream>
#include<stack>
#include<string>
using namespace std;

//���� �̿� ����
/*
���� : ���������� ���� �� �� �ִ� ���� ����.(������ ����� �������� �Ͼ)
ó���� push�� ���� �ؿ� ��
S.push() : ������ ���ÿ� �ִ� ����
S.pop() : ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ���, ���� x�� ��� -1���
S.size() : ���ÿ� ����ִ� ������ ������ ���
S.empty() : ������ ��������� 1, �ƴϸ� 0�� ���
S.top() : ������ ���� ���� �ִ� ������ ���, ���� X�� ��� -1���
*/

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, num;
	cin >> N;

	stack<int> S;
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push") {
			cin >> num;
			S.push(num);
		}
		else if (input == "top") {
			if (S.size() == 0)
				cout << -1 << endl;
			else {
				cout << S.top() << endl;
			}
		}
		else if (input == "size") {
			cout << S.size() << endl;
		}
		else if(input == "pop") {
			if (S.size() == 0)
				cout << -1 << endl;
			else {
				cout << S.top() << endl;
				S.pop();
			}
		}
		else if (input == "empty") {
			cout << S.empty() << endl;
		}
	}

	return 0;
}

