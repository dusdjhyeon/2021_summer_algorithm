#include<iostream>
using namespace std;

//binary code
//����Լ�

void binary(unsigned long long n) {
	if (n != 1)
		binary(n / 2);
	cout << n % 2;
}

int main(void) {
	long long  N;
	cin >> N;

	binary(N);

	return 0;
}