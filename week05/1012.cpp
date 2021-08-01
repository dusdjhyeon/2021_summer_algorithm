#include<iostream>
#include<cstring>
using namespace std;

//BFS(Breadth First Search)
// ㄴ> 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문

//memset 함수
// ㄴ> 어떤 메모리의 시작점부터 연속된 범위를 어떤 값(바이트 단위)으로 모두 지정하고 싶을 때 사용
/*
void* memset(void *ptr, int value size_t num); 형태
ptr: 채우고자 하는 메모리의 시작 포인터
vlaue: 메모리에서 채우고자 하는 값(unsigned char로 변환되어 저장 됨)
num: 채우고자 하는 바이트의 수, 채우고자 하는 메모리의 크기
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

