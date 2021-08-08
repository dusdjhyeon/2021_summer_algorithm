#include<iostream>
using namespace std;

//쉬운 문제나 longlong int 같은 형태 주의...
/*
long : 4bytes
long long : 8bytes
*/

int N, B, C;
int A[1000001];

int main(void) {
	long long int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		count++;

		if (A[i] > 0) {
			if (A[i] % C == 0)
				count += (A[i] / C);
			else
				count += (A[i] / C) + 1;
		}
	}
	cout << count << '\n';

	return 0;
}