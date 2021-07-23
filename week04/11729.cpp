#include<iostream>
#include<cmath>
using namespace std;

//hanoi tower
/*
m(k) = m(k-1) + 1 + m(k-1) = k-1°³(A->B) + 1¹ø(A->C) + k-1°³(B->C)
=> m(k) = 2m(k-1) + 1
=> m(k) = 2^0 + 2^1 + ... + 2^(k-1) = 1(2^n - 1)/2 - 1
*/

int N, K, A, B;

void hanoi(int n, int start, int mid, int end) {
	if (n == 1)
		cout << start << " " << end << '\n';//A->C
	else {
		hanoi(n - 1, start, end, mid);//A->B
		cout << start << " " << end << '\n';
		hanoi(n -1, mid, start, end);//B->C
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 2, 3);

	return 0;
}



