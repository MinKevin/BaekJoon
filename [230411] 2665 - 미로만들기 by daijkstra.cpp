#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> t;

int n;
string board[51];
int vis[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
priority_queue<t, vector<t>, greater<t>> pq;

int solution() {

	pq.push({ 1, 0, 0 });
	vis[0][0] = 1;

	while (!pq.empty()) {
		tuple<int, int, int> cur = pq.top();
		pq.pop();
		cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (nx == n - 1 && ny == n - 1)
				return get<0>(cur) - 1;

			
			if (vis[nx][ny] == 0) {
				int comparison = vis[get<1>(cur)][get<2>(cur)] +
					(board[nx][ny] == '1' ? 0 : 1);
				vis[nx][ny] = comparison;
				pq.push({ comparison, nx, ny });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	cout << solution();
}