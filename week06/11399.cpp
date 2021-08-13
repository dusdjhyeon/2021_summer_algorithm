#include<iostream>
#include<algorithm>
using namespace std;

int N;
int P[1001];

int main(void) {
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P, P + N);//오름차순
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			result += P[j];

	cout << result << '\n';

	return 0;
}