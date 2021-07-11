#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//요세푸스 문제
//queue이용해서 풀어봄 
//list나 vector 이용해도 좋을듯

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