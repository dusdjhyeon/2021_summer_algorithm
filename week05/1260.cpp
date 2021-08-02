#include<iostream>
using namespace std;

//dfs(Depth First Search)
// ㄴ> 다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문

//bfs(Breadth First Search)
// ㄴ> 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문

int N, M, V;
int x, y;
int sea[1001][1001];
int fi[1001];//기본값은 null (0)
queue<int> b;

void dfs(int v) {
	cout << v << ' ';
	fi[v] = 1;//이미 한것 0->1
	for (int i = 1; i <= N; i++) {
		if (fi[i] == 1 || sea[v][i] == 0)
			continue;
		dfs(i);//방문 x, main 에서 입력 받은 경우 => 재귀
	}
}

void bfs(int v) {
	b.push(v);
	fi[v] = 0;//이미한 것 0->1->0
	while (!b.empty()) {
		v = b.front();
		cout << b.front() << ' ';
		b.pop();
		for (int i = 1; i <= N; i++) {
			if (fi[i] == 0 || sea[v][i] == 0)
				continue;
			b.push(i);
			fi[i] = 0;
		}
	}
}

int main(void) {
	cin >> N >> M >> V;

	while (M--) {
		cin >> x >> y;
		sea[x][y] = sea[y][x] = 1;//간선은 양방향
	}
	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}