#include<iostream>
#include<vector>
using namespace std;

//binary tree
/*
전위 순회(pre()) : 루트 - 왼쪽 자식 - 오른쪽 자식
중위 순회(in())) : 왼쪽 자식 - 루트 - 오른쪽 자식
후위 순회(gu())) : 왼쪽 자식 - 오른쪽 자식 - 루트
*/

vector<pair<int, bool>>tree[30];//트리는 왼, 오 자식을 true false로 나눔 

void pre(int n) {
	cout << (char)(n + 'A');
	for (int i = 0; i < tree[n].size(); i++)
		pre(tree[n][i].first);
}

void in(int n) {
	if (tree[n].size() && tree[n][0].second)//자식 o , 왼쪽
		in(tree[n][0].first);
	cout << (char)(n + 'A');

	if (tree[n].size() && !tree[n][0].second)
		in(tree[n][0].first);

	//양쪽 모두 자식 o
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
		//항상 A가 루트 노드
		//왼쪽 자식
		if (y != '.') {
			tree[x - 'A'].push_back({ y - 'A', true });//y-'A'는 루트인 A를 기준으로 표준화 시키는 것 
		}
		//오른쪽 자식
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