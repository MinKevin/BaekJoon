#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
string board[51];
int cnt[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS() {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	cnt[0][0] = 0;

	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();

		if (cnt[get<0>(cur)][get<1>(cur)] != -1 && cnt[get<0>(cur)][get<1>(cur)] < get<2>(cur))
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			int comparison = cnt[get<0>(cur)][get<1>(cur)] +
				(board[nx][ny] == '1' ? 0 : 1);

			if (cnt[nx][ny] > comparison || cnt[nx][ny] == -1) {
				cnt[nx][ny] = comparison;
				q.push({ nx, ny, cnt[nx][ny] });
			}
		}
	}
	cout << cnt[n - 1][n - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	fill(&cnt[0][0], &cnt[n - 1][n], -1);
	BFS();
}