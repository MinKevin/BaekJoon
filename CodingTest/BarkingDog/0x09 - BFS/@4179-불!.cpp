#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

char board[1000][1000];
int vis[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int R, C;
pair<int, int> locJ;
queue < pair<int, int>> locF;

int BFS() {
	queue<pair<int, int>> q;

	q.push(locJ);

	while (!locF.empty()) {
		q.push(locF.front());
		locF.pop();
	}

	if (locJ.first == 0 || locJ.first == R - 1 || locJ.second == 0 || locJ.second == C - 1) {
		return 1;
	}

	while (!q.empty()) {
		pair<int, int> cur;
		cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;

			if (board[cur.X][cur.Y] == 'J') {
				if (cur.X == 0 || cur.X == R - 1 || cur.Y == 0 || cur.Y == C - 1)
					return vis[cur.X][cur.Y];

				if (board[nx][ny] == '.') {
					board[nx][ny] = 'J';
					vis[nx][ny] = vis[cur.X][cur.Y] + 1;
					q.push({ nx, ny });


				}
			}

			else if (board[cur.X][cur.Y] == 'F') {
				if (board[nx][ny] == '.' || board[nx][ny] == 'J') {
					board[nx][ny] = 'F';
					q.push({ nx, ny });
				}
			}
		}
		//cout << "-------------\n";
		//for (int i = 0; i < R; i++)
		//	cout << board[i] << '\n';
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> board[i];
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'J') {
				locJ = make_pair(i, j);
				vis[i][j] = 1;
			}
			else if (board[i][j] == 'F')
				locF.push({ i, j });
		}
	}

	int result = BFS();

	if (result == -1)
		cout << "IMPOSSIBLE";

	else
		cout << result;

}