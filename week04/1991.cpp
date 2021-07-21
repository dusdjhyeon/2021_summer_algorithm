#include<iostream>
#include<vector>
using namespace std;

//binary tree
/*
���� ��ȸ(pre()) : ��Ʈ - ���� �ڽ� - ������ �ڽ�
���� ��ȸ(in())) : ���� �ڽ� - ��Ʈ - ������ �ڽ�
���� ��ȸ(gu())) : ���� �ڽ� - ������ �ڽ� - ��Ʈ
*/

vector<pair<int, bool>>tree[30];//Ʈ���� ��, �� �ڽ��� true false�� ���� 

void pre(int n) {
	cout << (char)(n + 'A');
	for (int i = 0; i < tree[n].size(); i++)
		pre(tree[n][i].first);
}

void in(int n) {
	if (tree[n].size() && tree[n][0].second)//�ڽ� o , ����
		in(tree[n][0].first);
	cout << (char)(n + 'A');

	if (tree[n].size() && !tree[n][0].second)
		in(tree[n][0].first);

	//���� ��� �ڽ� o
	else if (tree[n].size() == 2)
		in(tree[n][1].first);
}

void gu(int n) {
	for (int i = 0; i < tree[n].size(); i++)
		gu(tree[n][i].first);
	cout << (char)(n + 'A');
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	char x, y, z;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		//�׻� A�� ��Ʈ ���
		//���� �ڽ�
		if (y != '.') {
			tree[x - 'A'].push_back({ y - 'A', true });//y-'A'�� ��Ʈ�� A�� �������� ǥ��ȭ ��Ű�� �� 
		}
		//������ �ڽ�
		if (z != '.') {
			tree[x - 'A'].push_back({ z - 'A', false });
		}
	}

	pre(0);
	cout << '\n';
	in(0);
	cout << '\n';
	gu(0);
	cout << '\n';

	return 0;
}