#include<iostream>
using namespace std;

//binary tree
/*
BT : 
�ڽ� x ��� : �������
��� ��ȸ ��� =>
   ���� ��ȸ(preorder) : ��Ʈ - ���� �ڽ� - ������ �ڽ�
   ���� ��ȸ(inorder) : ���� �ڽ� - ��Ʈ - ������ �ڽ�
   ���� ��ȸ(postorder) : ���� �ڽ� - ������ �ڽ� - ��Ʈ
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