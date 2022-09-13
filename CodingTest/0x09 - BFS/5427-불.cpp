#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[1000][1000];
int vis[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int T, w, h;
pair<int, int> locSG;
queue<pair<pair<int, int>, int>> q;
queue<int> answer;
int BFS() {

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first.first + dx[dir];
			int ny = cur.first.second + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;

			if (cur.second == 1) {
				if (board[nx][ny] == '.' || board[nx][ny] == '@') {
					board[nx][ny] = '*';
					q.push({ {nx, ny}, 1 });
				}
			}
			else if (cur.second == 0) {
				if (board[nx][ny] == '.') {
					board[nx][ny] = '@';
					vis[nx][ny] = vis[cur.first.first][cur.first.second] + 1;
					q.push({ { nx, ny }, 0 });
					if (nx == 0 || nx == h - 1 || ny == 0 || ny == w - 1) {
						return vis[nx][ny];
					}
				}
			}
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		memset(vis, 0, sizeof(vis));
		fill(&vis[0][0], &vis[999][1000], 0);

		while (!q.empty())
			q.pop();
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> board[i];
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '@')
					locSG = make_pair(i, j);
				else if (board[i][j] == '*')
					q.push({ { i, j }, 1 });
			}
		}
		vis[locSG.first][locSG.second] = 1;
		q.push({ locSG, 0 });

		if (locSG.first == 0 || locSG.first == h - 1 || locSG.second == 0 || locSG.second == w - 1) {
			answer.push(1);
			continue;
		}

		answer.push(BFS());
	}

	while (!answer.empty()) {
		if (answer.front() == 0)
			cout << "IMPOSSIBLE\n";
		else
			cout << answer.front() << '\n';

		answer.pop();
	}
}