#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//���� �̿� ����
/*
1. �Էµ� ���ں��� stack top�� ���ڰ� ���� ��� push
2. ������ pop
3. stack top�� �Էµ� ���ں��� Ŭ ��� NO
##stack empty() ����
=>s���� pop�� ���� ���� ������� �� �������� ������ ���� t�� ���� �� ������ ����� ������ ���, �ƴϸ� no�� ���
*/

//���� �� ��
/*
����� ���� ��� endl�� ����ϸ� �ð��� �����(endl�� ���� �� ���� ���ű��� �ϱ� ����)
=> '\n'����ϱ�
*/

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, number;
	stack<int> stk;
	vector<int> num;
	vector<char> vec;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number;
		num.push_back(number);
	}
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		stk.push(i);
		vec.push_back('+');
		while (!stk.empty()) {
			if (num[idx] == stk.top()) {
				vec.push_back('-');
				stk.pop();
				idx++;
			}
			else {
				break;
			}
		}
	}
	if (stk.empty()) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}

