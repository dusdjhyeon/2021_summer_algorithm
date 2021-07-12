#include<iostream>
#include<deque>
using namespace std;

//deque 이용 문제(삼성 기출)
/*
빈자리 = 0, 뱀 자리 = 2
꼬리(back) = 0, 사과 = 1, 꼬리(front) = 2
*/

//동북서남
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
	//방향연산의 횟수 
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
	int x = 1, y = 1, direction = 0, cnt = 0;//cnt= 연산의 갯수
	s.push_back({ x,y });//뱀의 초기 좌표
	map[x][y] = 2;
	while (1)
	{
		time++;
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		//벽이나, 자신과 만나면 끝
		if (nx<1 || ny<1 || nx>n || ny>n || map[nx][ny] == 2)
			return;

		else if (map[nx][ny] == 0)//빈칸일 때
		{
			map[nx][ny] = 2;//새로운 머리 자리 = 2
			map[s.back().first][s.back().second] = 0;//기존 꼬리 자리 = 0
			s.pop_back();//꼬리 자르기
			s.push_front({ nx,ny });//새로운 머리 push
		}
		else if (map[nx][ny] == 1)//사과 만날 때
		{
			map[nx][ny] = 2;
			s.push_front({ nx, ny });//머리 == 사과 만난 자리
		}

		if (cnt < d.size()) {
			//연산 횟수에대해 방향갱신
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