#include<iostream>
#include<cmath>
using namespace std;

int N;
int power[21][21];
bool visit[21];
int result = 123456789;

void team(int num, int cur) {
	if (num == N / 2) {
		int x = 0;
		int y = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visit[i] && visit[j]) {
					x += power[i][j];
					x += power[j][i];
				}
				else if (!visit[i] && !visit[j]) {
					y += power[i][j];
					y += power[j][i];
				}
			}
		}
		result = min(result, abs(x - y));
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == false && i > cur) {
			visit[i] = true;
			team(num + 1, i);
			visit[i] = false;
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> power[i][j];

	team(0, -1);
	cout << result << '\n';

	return 0;
}