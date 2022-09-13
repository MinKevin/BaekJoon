#include <iostream>
#include <queue>

using namespace std;

int board[300][300];
int dx[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int T, I;
pair<int, int> target;
queue<pair<int, int>> q;
queue<int> answer;

int BFS() {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.first == target.first && cur.second == target.second) {
			return 0;
		}

		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx == target.first && ny == target.second) {
				return board[cur.first][cur.second];
			}

			if (nx < 0 || nx >= I || ny < 0 || ny >= I)
				continue;

			if (board[nx][ny] == 0) {
				board[nx][ny] = board[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		int x, y;

		//memset(board, 0, sizeof(board));
		fill(&board[0][0], &board[299][300], 0);
		while (!q.empty())
			q.pop();


		cin >> I;
		cin >> x >> y;
		q.push({ x, y });
		board[x][y] = 1;

		cin >> x >> y;
		target = make_pair(x, y);

		answer.push(BFS());
	}

	while (!answer.empty()) {
		cout << answer.front() << '\n';
		answer.pop();
	}
}