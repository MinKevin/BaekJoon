#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, h;
int board[100][100][100];
int cnt[2];
queue<tuple<int, int, int>> q;

int dx[8] = { 1, -1, 0, 0, 0, 0 };
int dy[8] = { 0, 0, 1, -1, 0, 0 };
int dz[8] = { 0, 0, 0, 0, 1, -1 };

void input() {
	cin >> n >> m >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> board[k][j][i];
				if (board[k][j][i] != -1)
					cnt[board[k][j][i]]++;
				if (board[k][j][i] == 1)
					q.push(make_tuple(k, j, i));
			}
		}
	}
}

int solution() {//bfs
	if (cnt[1] == 0)
		return -1;

	int answer = 0;
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();
		int x = get<0>(cur);
		int y = get<1>(cur);
		int z = get<2>(cur);

		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;

			if (board[nx][ny][nz] == 0) {
				cnt[0]--;
				board[nx][ny][nz] = board[x][y][z] + 1;
				answer = board[x][y][z];
				q.push({ nx, ny, nz });
			}
		}
	}
	if (cnt[0] != 0)
		return -1;
	else
		return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}