#include <iostream>
#include <queue>

using namespace std;

int vis[100001];
int dx[3] = { -1, 0, 1 };
int N, K;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	vis[N] = 1;

	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int cur;
		cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 1)
				nx = cur * 2;
			else
				nx = cur + dx[dir];

			if (nx < 0 || nx > 100000)
				continue;

			if (vis[nx] == 0) {
				vis[nx] = vis[cur] + 1;
				q.push(nx);
			}

			if (nx == K) {
				cout << vis[nx] - 1;
				return 0;
			}
		}
	}
}