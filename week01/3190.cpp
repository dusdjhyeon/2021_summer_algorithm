#include<iostream>
#include<deque>
using namespace std;

//deque �̿� ����(�Ｚ ����)
/*
���ڸ� = 0, �� �ڸ� = 2
����(back) = 0, ��� = 1, ����(front) = 2
*/

//���ϼ���
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int map[100][100];
deque<pair<int, char>>d;
deque<pair<int, int>>s;
void func();
int n, time;
int main()
{
	int k, x, y, l, num;
	char c;
	//���⿬���� Ƚ�� 
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
	}
	cin >> l;
	for (int i = 1; i <= l; i++)
	{
		cin >> num >> c;
		d.push_back({ num, c });
	}

	func();
	cout << time << endl;
}
void func()
{
	int x = 1, y = 1, direction = 0, cnt = 0;//cnt= ������ ����
	s.push_back({ x,y });//���� �ʱ� ��ǥ
	map[x][y] = 2;
	while (1)
	{
		time++;
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		//���̳�, �ڽŰ� ������ ��
		if (nx<1 || ny<1 || nx>n || ny>n || map[nx][ny] == 2)
			return;

		else if (map[nx][ny] == 0)//��ĭ�� ��
		{
			map[nx][ny] = 2;//���ο� �Ӹ� �ڸ� = 2
			map[s.back().first][s.back().second] = 0;//���� ���� �ڸ� = 0
			s.pop_back();//���� �ڸ���
			s.push_front({ nx,ny });//���ο� �Ӹ� push
		}
		else if (map[nx][ny] == 1)//��� ���� ��
		{
			map[nx][ny] = 2;
			s.push_front({ nx, ny });//�Ӹ� == ��� ���� �ڸ�
		}

		if (cnt < d.size()) {
			//���� Ƚ�������� ���ⰻ��
			if (time == d[cnt].first)
			{
				if (d[cnt].second == 'L')
					direction = (direction + 1) % 4;
				else if (d[cnt].second == 'D')
					direction = (direction + 3) % 4;
				cnt++;
			}
		}
		x = nx;
		y = ny;
	}
}