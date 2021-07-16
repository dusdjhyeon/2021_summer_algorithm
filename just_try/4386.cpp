#include<iostream>
#include<algorithm>
#include<deque>
#include<cmath>
using namespace std;
//mimimum spanning tree
/*
ũ�罺Į �˰��� ����, cycle ���� Ȯ��(union-find)
Kruskal algorithm(��带 �ּ����� ������� �����ϴ� �ּ� ��� ���� Ʈ�� ���ϴ� ��ǥ �˰���)
*���� Ʈ���� cycle ���� x
*/
int n;
float x, y;
int verify[101] = { 0, };
double check = 0;
deque<pair<float, float>> star;//for ���� ��ǥ
deque<pair<double, pair<int, int>>>v;

int find(int s) {
	if (s == verify[s]) {
		return s;
	}
	return verify[s] = find(verify[s]);
}

double cal(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		star.push_back({ x,y });
	}
	
	//�� ���� �Ÿ� ����
	for (int i = 0; i < star.size(); i++) {
		for (int j = i + 1; j < star.size(); j++) {
			double distance = cal(star[i].first, star[i].second, star[j].first, star[j].second);
			v.push_back({ distance,{i,j} });
		}
	}

	for (int i = 0; i <n; i++) {
		verify[i] = i;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		double cost = v[i].first;

		int a = find(x);
		int b = find(y);

		if (a != b) {
			verify[a] = b;
			check += cost;
		}
	}

	cout.precision(3);//�Ҽ��� �ڸ� �� ����
	cout << check << '\n';

	return 0;
}