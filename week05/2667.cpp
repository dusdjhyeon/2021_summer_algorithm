#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N;
bool table[25][25];
bool check[25][25];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    int count = 0;
    cin >> N;
    string num;

    //아래는 띄어쓰기 없이 입력 받는 방법
    for (int i = 0; i < N; i++) {
        cin >> num;
        for (int j = 0; j < N; j++)
            table[i][j] = num[j] - '0';
    }
    vector<int> wide;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check[i][j] && table[i][j] == 1) {
                int cnt = 1;
                q.push(make_pair(i, j));
                check[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = dx[i] + x;
                        int ny = dy[i] + y;
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            if (!check[nx][ny] && table[nx][ny] == 1) {
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = true;
                                cnt += 1;
                            }
                        }
                    }
                }
                wide.push_back(cnt);
            }
        }
    }
    sort(wide.begin(), wide.end());
    cout << wide.size() << '\n';
    for (int i = 0; i < wide.size(); i++) {
        cout << wide[i] << '\n';
    }

    return 0;
}