#include <iostream>
#include <vector>
using namespace std;

//������ ������ ����
//���� �Ǵ� �迭 �̿�

int N;
vector<int> W(10);
int Max = -1;

void energy(vector<int> W, int sum) {
	int num = W.size();//���� ���� ���� ��
	//������ 3�� ���� ���
	if (num == 3) {
		sum += W[0] * W[2];
		if (Max < sum)
			Max = sum;
		
	}
	for (int i = 1; i < num - 1; i++) {//�� �հ� �� �� ���� ������ ����
		int temp = W[i];
		sum += W[i - 1] * W[i + 1];
		vector<int>w_w = W;
		w_w.erase(w_w.begin() + i);//w_w[0]�� �ƴ� w_w.begin()���
		energy(w_w, sum);
		sum -= W[i - 1] * W[i + 1];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	energy(W, 0);
	cout << Max << '\n';
	return 0;
}