#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//�׸���(Ž��) �˰��� �м� ����
/*
1������ ������� 2������ �Ŷ�� ��(deadline, cup)
������ ��=> (1,20) (2,30) (2,24)�� �־��� ��� (1,20), (2,30)�� �����ϴ°� ���� (2,24), (2,30)�� �����ϴ� ���� �̵�
*/

typedef pair<int, int>Greed;

int main(void) {
	int N;
	cin >> N;
	vector<Greed>arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < N; i++) {
		if (pq.size() < arr[i].first) {//pq.size�� �帥 �����ð� ��
			pq.push(arr[i].second);
		}
		else {
			if (pq.top() < arr[i].second) {
				pq.pop();
				pq.push(arr[i].second);
			}
		}
	}
	int sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}
