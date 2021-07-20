#include <iostream>
#include <vector>
using namespace std;

//에너지 모으기 문제
//벡터 또는 배열 이용

int N;
vector<int> W(10);
int Max = -1;

void energy(vector<int> W, int sum) {
	int num = W.size();//현재 남은 구슬 수
	//구슬이 3개 남은 경우
	if (num == 3) {
		sum += W[0] * W[2];
		if (Max < sum)
			Max = sum;
		
	}
	for (int i = 1; i < num - 1; i++) {//맨 앞과 맨 끝 구슬 제외한 진행
		int temp = W[i];
		sum += W[i - 1] * W[i + 1];
		vector<int>w_w = W;
		w_w.erase(w_w.begin() + i);//w_w[0]이 아닌 w_w.begin()사용
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