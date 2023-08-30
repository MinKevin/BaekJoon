#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int M, N;
vector<string> board;
vector<vector<int>> vis;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void input() {
	cin >> M >> N;
	board.resize(N);
	vis.resize(N, vector<int>(M, INT_MAX));

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
}

int solution() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	
	if (board[0][0] == '0') {
		pq.push({ 0, {0, 0} });
		vis[0][0] = 0;
	}
	else {
		pq.push({ 1, {0, 0} });
		vis[0][0] = 1;
	}

	while (!pq.empty()) {
		int cnt = pq.top().first;
		pair<int, int> cur = pq.top().second;
		pq.pop();

		if (vis[N - 1][M - 1] != INT_MAX)
			return vis[N - 1][M - 1];

		if (vis[cur.first][cur.second] < cnt)
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (vis[nx][ny] > cnt + board[nx][ny] - '0') {
				vis[nx][ny] = cnt + board[nx][ny] - '0';
				pq.push({ vis[nx][ny], {nx, ny} });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}