#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//스택 이용 문제
/*
1. 입력된 숫자보다 stack top의 숫자가 작을 경우 push
2. 같으면 pop
3. stack top이 입력된 숫자보다 클 경우 NO
##stack empty() 주의
=>s에서 pop한 수로 수열 만들었을 때 문제에서 제시한 수열 t를 만들 수 있으면 만드는 순서를 출력, 아니면 no를 출력
*/

//새로 안 점
/*
출력이 많은 경우 endl로 출력하면 시간이 길어짐(endl은 개행 후 버퍼 제거까지 하기 때문)
=> '\n'사용하기
*/

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, number;
	stack<int> stk;
	vector<int> num;
	vector<char> vec;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number;
		num.push_back(number);
	}
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		stk.push(i);
		vec.push_back('+');
		while (!stk.empty()) {
			if (num[idx] == stk.top()) {
				vec.push_back('-');
				stk.pop();
				idx++;
			}
			else {
				break;
			}
		}
	}
	if (stk.empty()) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}

