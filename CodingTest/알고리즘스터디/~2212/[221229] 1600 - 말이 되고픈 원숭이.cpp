/*
Date : 22.12.29
Time : 15:25
Comment : 
*/

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int K, W, H;
int board[200][200];
int kindsCnt[200][200][31];
int dx[12] = { 0, 0, 1, -1, 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[12] = { 1, -1, 0, 0, -2, 2, -1, 1, -2, 2, -1, 1 };
int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	kindsCnt[0][0][0] = 1;

	while(!q.empty()) {
		if (W == 1 && H == 1) {
			return 0;
		}

		tuple<int, int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 12; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];

			if (nx < 0 || ny < 0 || nx >= H || ny >= W)
				continue;

			if (nx == H - 1 && ny == W - 1) {
				if (dir < 4)
					return kindsCnt[get<0>(cur)][get<1>(cur)][get<2>(cur)];
				else if (get<2>(cur) < K)
					return kindsCnt[get<0>(cur)][get<1>(cur)][get<2>(cur)];
			}

			if (dir < 4) {
				if (board[nx][ny] == 0 && kindsCnt[nx][ny][get<2>(cur)] == 0) {
					kindsCnt[nx][ny][get<2>(cur)] = kindsCnt[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
					q.push({ nx, ny, get<2>(cur) });
				}
			}
			else {
				if (get<2>(cur) < K && board[nx][ny] == 0 && kindsCnt[nx][ny][get<2>(cur) + 1] == 0) {
					kindsCnt[nx][ny][get<2>(cur) + 1] = kindsCnt[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
					q.push({ nx, ny, get<2>(cur) + 1 });
				}
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	cout << bfs();
}