#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	int K, num;
	int result = 0;
	stack<int> list;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0)
			list.pop();
		else
			list.push(num);
	}

	for (int i = 0; !list.empty(); i++) {
		result += list.top();
		list.pop();
	}
	cout << result << '\n';


	return 0;
}