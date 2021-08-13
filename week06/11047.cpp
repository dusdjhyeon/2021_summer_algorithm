#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int A[11];

void money(int& K, int change, int& count) {
	if (K >= change) {
		count += K / change;
		K -= (K / change) * change;
	}
}

int main(void) {
	cin >> N >> K;
	int count = 0;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N, greater<>());

	for (int i = 0; i < N; i++) {
		money(K, A[i], count);
	}

	cout << count << '\n';

	return 0;
}