#include<iostream>
using namespace std;

//�׷��� ����(N-1)
/*
������ �պ� ����Ⱑ �ִٴ� ���� �ǹ��ϴ� a�� b�� �߿����� �ʴ�
�ᱹ �ּ� N���� ������ �̸����� n-1���� ������ �־�� �Ѵٴ�
�׷����� ������ �̿��� ��
*/

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N, M, a, b;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int m = 0; m < M; m++) {
			cin >> a >> b;
		}
		cout << N - 1 << '\n';
	}
}

