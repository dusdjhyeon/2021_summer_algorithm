#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> q;
int n, m;
bool paper[501][501];
bool check[501][501];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main(void) {
	int num = 0;
	int max = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int wide = 0;
			if (paper[i][j] == 1 && check[i][j] != 1) {//방문x, 색칠 o
				check[i][j] = 1;//방문함
				num++;
				wide++;
				q.push({ i,j });
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (check[nx][ny] || !paper[nx][ny])
							continue;
						check[nx][ny] = 1;
						q.push({ nx, ny });
						wide++;
					}
				}
				if (max <= wide)
					max = wide;
			}
		}
	}

	cout << num << '\n' << max;

	return 0;
}