#include<iostream>
#include<stack>
#include<string>
using namespace std;

//스택 이용 문제
/*
스택 : 제한적으로 접근 할 수 있는 나열 구조.(언제나 목록의 끝에서만 일어남)
처음에 push된 수가 밑에 깔림
S.push() : 정수를 스택에 넣는 연산
S.pop() : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력, 정수 x의 경우 -1출력
S.size() : 스택에 들어있는 정수의 개수를 출력
S.empty() : 스택이 비어있으면 1, 아니면 0을 출력
S.top() : 스택의 가장 위에 있는 정수를 출력, 정수 X의 경우 -1출력
*/

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, num;
	cin >> N;

	stack<int> S;
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push") {
			cin >> num;
			S.push(num);
		}
		else if (input == "top") {
			if (S.size() == 0)
				cout << -1 << endl;
			else {
				cout << S.top() << endl;
			}
		}
		else if (input == "size") {
			cout << S.size() << endl;
		}
		else if(input == "pop") {
			if (S.size() == 0)
				cout << -1 << endl;
			else {
				cout << S.top() << endl;
				S.pop();
			}
		}
		else if (input == "empty") {
			cout << S.empty() << endl;
		}
	}

	return 0;
}

