#include<iostream>
#include<queue>
using namespace std;

//최소 힙 이용문제
/*
최소 힙: 부모 노드의 키 값이 자식 노드의 키 값봅다 작거나 같은 완전 이진 트리
0이 나오면 최솟값 출력, 삭제
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