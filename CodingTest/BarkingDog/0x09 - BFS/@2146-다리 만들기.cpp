//반례
//5
//1 0 0 0 1
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 0
//0 1 0 0 1
//
//answer = 2;

#include <iostream>
#include <queue>

using namespace std;

int board[100][100];
pair<int, int> vis[100][100];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue<pair<pair<int, int>, int>> qBuf;
queue<pair<pair<int, int>, int>> q;
int N;

int BFS() {
	int landCount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && vis[i][j].first == 0) {
				vis[i][j] = {1, landCount};
				qBuf.push({ {i, j}, landCount });
				q.push({ {i, j}, landCount++ });

				while (!qBuf.empty()) {
					pair<pair<int, int>, int> cur = qBuf.front();
					qBuf.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first.first + dx[dir];
						int ny = cur.first.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						if (board[nx][ny] == 1 && vis[nx][ny].first == 0) {
							vis[nx][ny] = { 1, cur.second };
							qBuf.push({ {nx, ny}, cur.second });
							q.push({ {nx, ny}, cur.second });
						}
					}
				}
			}
		}
	}
	int answer = 200;
	while (!q.empty()) {
		int qSize = q.size();

		while (qSize--) {
			pair<pair<int, int>, int> cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first.first + dx[dir];
				int ny = cur.first.second + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;

				if (board[nx][ny] == 0 && vis[nx][ny].first == 0) {
					vis[nx][ny] = { vis[cur.first.first][cur.first.second].first + 1, vis[cur.first.first][cur.first.second].second };
					q.push({ {nx, ny}, cur.second });
				}
				else if (board[nx][ny] == 0 && vis[nx][ny].first <= vis[cur.first.first][cur.first.second].first + 1 && vis[nx][ny].second != cur.second) {
					int length = vis[nx][ny].first + vis[cur.first.first][cur.first.second].first - 2;
					if (answer > length)
						answer = length;
				}
			}
		}
		if (answer != 200)
			return answer;
	}
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



	cout << BFS() << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << vis[i][j].first << ' ';
		}
		cout << '\n';
	}
}