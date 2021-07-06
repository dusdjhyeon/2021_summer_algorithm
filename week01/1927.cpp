#include<iostream>
#include<queue>
using namespace std;

//�ּ� �� �̿빮��
/*
�ּ� ��: �θ� ����� Ű ���� �ڽ� ����� Ű ������ �۰ų� ���� ���� ���� Ʈ��
0�� ������ �ּڰ� ���, ����
*/

priority_queue<int, vector<int>, greater<int>> heap;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int element;
		cin >> element;
		if (!element && heap.empty())
			cout << 0 << '\n';
		else if (!element) {
			cout << heap.top() << "\n";
			heap.pop();
		}
		else
			heap.push(element);
	}

	return 0;
}