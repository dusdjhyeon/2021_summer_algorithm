#include<iostream>
#include<cstring>
using namespace std;

//BFS(Breadth First Search)
// ��> ������ �迭���� �� ĭ�� �湮�� �� �ʺ� �켱���� �湮

//memset �Լ�
// ��> � �޸��� ���������� ���ӵ� ������ � ��(����Ʈ ����)���� ��� �����ϰ� ���� �� ���
/*
void* memset(void *ptr, int value size_t num); ����
ptr: ä����� �ϴ� �޸��� ���� ������
vlaue: �޸𸮿��� ä����� �ϴ� ��(unsigned char�� ��ȯ�Ǿ� ���� ��)
num: ä����� �ϴ� ����Ʈ�� ��, ä����� �ϴ� �޸��� ũ��
*/

bool check[51][51];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int a[51][51];
int T, M, N, K;
void cabbage(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (a[nx][ny] == 1) {
				if (!check[nx][ny]) {
					cabbage(nx, ny);
				}
			}
		}
		else continue;
	}
}
int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		int cnt = 0;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == 1) {
					if (!check[i][j]) {
						cnt++;
						cabbage(i, j);
					}
				}
			}
		}
		cout << cnt << '\n';
		memset(check, false, sizeof(check));
		memset(a, 0, sizeof(a));
	}
}

