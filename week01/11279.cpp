#include<iostream>
#include<queue>
using namespace std;

//최대 힙 이용 문제
/*
최대 힙: 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리
0이 오면 가장 큰 값 출력 후 제거, 비어 있으면 0 출력
*/

priority_queue<int, vector<int>, less<int>> heap;

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
			cout << heap.top() << '\n';
			heap.pop();
		}
		else
			heap.push(element);
	}


	return 0;
}
