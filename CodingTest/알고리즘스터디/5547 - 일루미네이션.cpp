/*
Date : 221124
Time : 00:39
Comment :
	문제 전체 다 읽고 푸는 습관을 가지자
	다 읽고 풀었으면 더 빨리 풀 수 있었다.
*/

#include <iostream>
#include <queue>

using namespace std;

int W, H;
int board[100][100];
int mask[100][100];
int dx[6] = { -1, -1, 0, 0, 1, 1 };
int dyEven[6] = { 0, 1, -1, 1, 0, 1 };
int dyOdd[6] = { 0, -1, 1, -1, 0, -1 };
int distance_;

void BFS() {
	queue<pair<int, int>> q;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (mask[i][j] == 0) {
				mask[i][j] = 1;
				q.push({ i, j });
				int cnt = 0;
				bool isOpen = false;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int dir = 0; dir < 6; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + (cur.first % 2 == 0 ? dyEven[dir] : dyOdd[dir]);

						if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
							if (board[cur.first][cur.second] == 1) {
								cnt++;
								continue;
							}
							else {
								isOpen = true;
								continue;
							}
						}

						if (board[nx][ny] != board[cur.first][cur.second]) {
							cnt++;
						}

						else if (board[nx][ny] == board[cur.first][cur.second] && mask[nx][ny] == 0) {
							q.push({ nx, ny });
							mask[nx][ny] = 1;
						}
					}
				}
				if (board[i][j] == 1)
					distance_ += cnt;
				else {
					if (isOpen == false)
						distance_ -= cnt;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	BFS();

	cout << distance_;
}