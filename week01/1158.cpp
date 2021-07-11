#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//�似Ǫ�� ����
//queue�̿��ؼ� Ǯ� 
//list�� vector �̿��ص� ������

int main(void) {
	int num, data;
	queue<int> q;

	cin >> num >> data;
	cout << "<";
	for (int i = 1; i <= num; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int j = 0; j < data - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
	}

	cout << ">";

}