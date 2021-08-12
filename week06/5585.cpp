#include<iostream>
using namespace std;

void charge(int& money, int change, int& count) {
	if (money >= change) {
		count += money / change;
		money -= (money / change) * change;
	}
}
int main(void) {
	int cha;
	cin >> cha;
	int count = 0;

	cha = 1000 - cha;

	charge(cha, 500, count);
	charge(cha, 100, count);
	charge(cha, 50, count);
	charge(cha, 10, count);
	charge(cha, 5, count);
	charge(cha, 1, count);

	cout << count << '\n';

	return 0;
}