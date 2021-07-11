#include<iostream>
#include<stack>
using namespace std;

//�� stack�� �̿��ϴ� ������ �ƴ����� stack�� �̿��� Ǯ����
/*
pair���� : pair<�ڷ���1, �ڷ���2> Ŭ������
Ŭ������.firt, Ŭ������.second��� ����
*/

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int count = 0;
	stack<pair<int, int>> s;//stack�� pair<int, int> ��
	cin >> N;

	for (int i = 0; i < N; i++) {
		bool flag;
		cin >> flag;
		if (flag) {
			int p, q;
			cin >> p >> q;
			s.push({ p,q });
		}
		if (!s.empty()) {
			s.top().second--;
			if (s.top().second == 0) {
				count += s.top().first;
				s.pop();
			}
		}
	}
	cout << count << '\n';

	return 0;
}

