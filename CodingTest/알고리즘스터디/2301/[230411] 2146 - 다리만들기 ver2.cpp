#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

typedef tuple<int, int, int> T;

int board[100][100];
pair<int, int> vis[100][100];
int N;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solution() {
	//vis.x = distance, vis.y = continentNum
	fill(&vis[0][0], &vis[N - 1][N], make_pair(-1, -1));
	queue<tuple<int, int, int>> q;//x, y, continentNum
	queue<tuple<int, int, int>> qSea;
	int cntContinent = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && vis[i][j].first == -1) {
				vis[i][j] = make_pair(0, cntContinent);
				q.push(make_tuple(i, j, cntContinent));
				cntContinent++;
				while (!q.empty()) {
					T cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = get<0>(cur) + dx[dir];
						int ny = get<1>(cur) + dy[dir];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
							continue;
						}
						if (vis[nx][ny].first == -1) {
							if (board[nx][ny] == 1) {
								vis[nx][ny] = make_pair(0, get<2>(cur));
								q.push({ nx, ny, get<2>(cur) });
							}
							else {//board[nx][ny] == 0
								vis[nx][ny] = make_pair(1, get<2>(cur));
								qSea.push({ nx, ny, get<2>(cur) });
							}
						}

						if (vis[nx][ny].first != -1 && vis[nx][ny].second != get<2>(cur)) {
							return 1;
						}
						
					}

				}
			}
		}
	}
	int findAnsTrial = 0;
	int ans = INT_MAX;
	while (!qSea.empty()) {
		T cur = qSea.front();
		qSea.pop();
		int x = get<0>(cur);
		int y = get<1>(cur);
		cntContinent = get<2>(cur);

		if (findAnsTrial != 0 && findAnsTrial != vis[x][y].first) {
			return ans;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}

			if (board[nx][ny] == 0) {
				if (vis[nx][ny].first == -1) {
					vis[nx][ny] = { vis[x][y].first + 1, vis[x][y].second };
					qSea.push({ nx, ny, cntContinent });
				}
				else if (vis[nx][ny].first != -1 && vis[nx][ny].second != cntContinent) {
					ans = min(ans, vis[x][y].first + vis[nx][ny].first);
					findAnsTrial = vis[x][y].first;
				}
			}
		}
	}

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	cout << solution() << '\n';

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		if (vis[i][j].first == -1)
	//			vis[i][j].first = 9;
	//		cout << vis[i][j].first << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		if (vis[i][j].second == -1)
	//			vis[i][j].second = 9;
	//		cout << vis[i][j].second << ' ';
	//	}
	//	cout << '\n';
	//}
}