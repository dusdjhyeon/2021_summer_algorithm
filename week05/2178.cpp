#include<iostream>
#include<string>
#include<queue>
using namespace std;

int N, M;
int maze[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (maze[nx][ny] == 0)
				continue;
			if (maze[nx][ny] == 1) {
				maze[nx][ny] = maze[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void) {
	string num;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < M; j++)
			maze[i][j] = num[j] - '0';
	}
	bfs(0, 0);
	cout << maze[N - 1][M - 1] << '\n';

	return 0;
}