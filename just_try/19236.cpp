#include<iostream>
#include<vector>
using namespace std;
//삼성 역량 sw문제(청소년 상어)

int result = 0;
//↑, ↖, ←, ↙, ↓, ↘, →, ↗
//중요: x = 행의 번호, y =  열의 번호, 반시계방향임
const int dx[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };// -1 = 상, +1 = 하
const int dy[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };// -1 = 좌, +1 = 우

struct Fish {
	int x = 0;
	int y = 0;
	int dir = 0; //물고기 이동방향
	int num = 0; //물고기 숫자
	bool live = true; //생존여부
};

void shark_g(vector<vector<int>>&v, Fish* fish, int shark_x, int shark_y, int sum) {
	vector<vector<int>> play(4, vector<int>(4));
	Fish f[16];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			play[i][j] = v[i][j];
		}
	}
	for (int i = 0; i < 16; i++)
		f[i] = fish[i];

	int mi = play[shark_x][shark_y];
	play[shark_x][shark_y] = -1;

	int shark_dir = f[mi].dir;
	f[mi].live = false;

	sum += f[mi].num;
	if (result < sum)
		result = sum;

	//fish move
	for (int i = 0; i < 16; i++) {
		if (f[i].live) {
			int x = f[i].x;
			int y = f[i].y;
			int dir = f[i].dir;

			int next_x = x + (dx[dir % 8]);
			int next_y = y + (dy[dir % 8]);

			while (next_x < 0 || next_x>3 || next_y < 0 || next_y>3 || (shark_x == next_x && shark_y == next_y)) {
				dir++;
				next_x = x + (dx[dir % 8]);
				next_y = y + (dy[dir % 8]);
			}

			if (play[next_x][next_y] != -1) {
				int swap = play[next_x][next_y];
				f[i].x = next_x;
				f[i].y = next_y;
				f[i].dir = dir;
				f[swap].x = x;
				f[swap].y = y;

				play[next_x][next_y] = i;
				play[x][y] = swap;
			}
			else {
				f[i].x = next_x;
				f[i].y = next_y;
				f[i].dir = dir;
				play[next_x][next_y] = i;
				play[x][y] = -1;
			}
		}
	}
	for (int i = 1; i < 4; i++) {
		int dir_x = dx[shark_dir % 8] * i;
		int dir_y = dy[shark_dir % 8] * i;
		int next_x = shark_x + dir_x;
		int next_y = shark_y + dir_y;

		if (next_x < 0 || next_x>3 || next_y < 0 || next_y>3)
			break;
		if (play[next_x][next_y] != -1)
			shark_g(play, f, next_x, next_y, sum);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n_um, d_ir;
	Fish fish[16]; //16마리의 물고기 정보
	vector<vector<int>> v(4, vector<int>(4)); //4 x 4 게임판

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> n_um >> d_ir;
			n_um--; d_ir--;
			v[i][j] = n_um;
			fish[n_um].x = i;
			fish[n_um].y = j;
			fish[n_um].dir = d_ir;
			fish[n_um].num = n_um + 1;
		}
	}
	shark_g(v, fish, 0, 0, 0);
	cout << result << '\n';

	return 0;
}