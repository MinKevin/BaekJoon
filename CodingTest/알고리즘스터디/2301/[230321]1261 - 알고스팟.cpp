#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

int N, M;
char board[101][101];
int value[101][101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int daijkstra() {
	if (board[0][0] == '1') {
		value[0][0] = 1;
		pq.push({ 1, 0, 0 });
	}
	else {
		value[0][0] = 0;
		pq.push({ 0, 0, 0 });
	}
	

	while (!pq.empty()) {
		int broken = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		if (value[x][y] < broken)
			continue;

		//cout << broken << ' ' << x << ' ' << y << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (value[nx][ny] > broken + board[nx][ny] - '0') {
				value[nx][ny] = broken + board[nx][ny] - '0';
				pq.push({ broken + board[nx][ny] - '0', nx, ny});
			}

				
		}
	}

	return value[N - 1][M - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	fill(&value[0][0], &value[100][101], INT_MAX);

	cout << daijkstra() << '\n';

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << value[i][j];
		}
		cout << '\n';
	}
	*/
}