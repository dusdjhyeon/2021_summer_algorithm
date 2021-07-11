#include<iostream>
#include<queue>
using namespace std;

//priority_queue : 우선순위에 맞게 설계된 container
//ㄴ> 힙과 유사

int main(void) {
	int case_n, N, M, im;
	int count = 0;
	cin >> case_n;
	
	for (int i = 0; i < case_n; i++) {
		count = 0;
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < N; j++) {
			cin >> im;
			q.push({ j,im });
			pq.push(im);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (value == pq.top()) {
				pq.pop();
				count++;
				if (index == M) {
					cout << count << endl;
					break;
				}
			}
			else
				q.push({ index, value });
		}
	}

	return 0;
}
