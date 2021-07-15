#include<iostream>
using namespace std;

//그래프 문제(N-1)
/*
국가간 왕복 비행기가 있다는 것을 의미하는 a와 b는 중요하지 않다
결국 최소 N개의 정점에 이르려면 n-1개의 간선이 있어야 한다는
그래프의 성질을 이용한 것
*/

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N, M, a, b;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int m = 0; m < M; m++) {
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}
}

