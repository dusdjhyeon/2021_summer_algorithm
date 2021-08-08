#include<iostream>
#include<algorithm>
using namespace std;

int N;
int T[16];//시간
int P[16];//금액
int tp[16];//최대금액
int result = 0;


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int day = 0; day < N + 1; day++) {
		int time = T[day];
		int price = P[day];
		int f = time + day;

		if (f >= N + 1)
			continue;
		for (int i = f; i < N + 1; i++)
			tp[i] = max(tp[day] + P[day], tp[i]);
	}
	cout << tp[N] << '\n';

	return 0;
}