#include<iostream>
using namespace std;

//binary tree
/*
BT : 
자식 x 노드 : 리프노드
노드 순회 방법 =>
   전위 순회(preorder) : 루트 - 왼쪽 자식 - 오른쪽 자식
   중위 순회(inorder) : 왼쪽 자식 - 루트 - 오른쪽 자식
   후위 순회(postorder) : 왼쪽 자식 - 오른쪽 자식 - 루트
*/

int T, n;
int pre[1000];
int in[1000];

void tree(int n, int root, int x) {
	for (int i = x; i < n; i++) {
		if (in[i] == pre[root]) {
			tree(i, root + 1, x);//left
			tree(n, root + i + 1 - x, i + 1);//right
			cout << pre[root] << " ";
		}
	}
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> in[i];
		}
		test(n, 0, 0);
		cout << '\n';
	}

	return 0;
}