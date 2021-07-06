#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//그리디(탐욕) 알고리즘 분석 문제
/*
1순위는 데드라인 2순위는 컵라면 수(deadline, cup)
주의할 점=> (1,20) (2,30) (2,24)가 주어질 경우 (1,20), (2,30)을 선택하는거 보다 (2,24), (2,30)을 선택하는 것이 이득
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
		if (pq.size() < arr[i].first) {//pq.size는 흐른 단위시간 수
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
