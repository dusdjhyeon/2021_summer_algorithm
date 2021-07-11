#include<iostream>
#include<stack>
using namespace std;

//꼭 stack을 이용하는 문제는 아니지만 stack을 이용해 풀었음
/*
pair사용법 : pair<자료형1, 자료형2> 클리스명
클래스명.firt, 클래스명.second사용 가능
*/

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int count = 0;
	stack<pair<int, int>> s;//stack의 pair<int, int> 형
	cin >> N;

	for (int i = 0; i < N; i++) {
		bool flag;
		cin >> flag;
		if (flag) {
			int p, q;
			cin >> p >> q;
			s.push({ p,q });
		}
		if (!s.empty()) {
			s.top().second--;
			if (s.top().second == 0) {
				count += s.top().first;
				s.pop();
			}
		}
	}
	cout << count << '\n';

	return 0;
}

