#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[25][25];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N;
vector<int> answer;

int BFS() {
	queue<pair<int, int>> q;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				q.push({ i, j });
				board[i][j] = 0;
				cnt++;

				int width = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						if (board[nx][ny] == 1) {
							board[nx][ny] = 0;
							width++;
							q.push({ nx, ny });
						}
					}
				}
				answer.push_back(width);
			}
		}
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		for (int j = 0; j < buf.size(); j++)
			board[i][j] = buf[j] - '0';
	}

	cout << BFS() << '\n';

	sort(begin(answer), end(answer), less<>());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}