#include<iostream>
using namespace std;

//dfs(Depth First Search)
// ��> ������ �迭���� �� ĭ�� �湮�� �� ���̸� �켱���� �湮

//bfs(Breadth First Search)
// ��> ������ �迭���� �� ĭ�� �湮�� �� �ʺ� �켱���� �湮

int N, M, V;
int x, y;
int sea[1001][1001];
int fi[1001];//�⺻���� null (0)
queue<int> b;

void dfs(int v) {
	cout << v << ' ';
	fi[v] = 1;//�̹� �Ѱ� 0->1
	for (int i = 1; i <= N; i++) {
		if (fi[i] == 1 || sea[v][i] == 0)
			continue;
		dfs(i);//�湮 x, main ���� �Է� ���� ��� => ���
	}
}

void bfs(int v) {
	b.push(v);
	fi[v] = 0;//�̹��� �� 0->1->0
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
		sea[x][y] = sea[y][x] = 1;//������ �����
	}
	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}