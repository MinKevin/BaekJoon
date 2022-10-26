#include <iostream>
#include <queue>

using namespace std;

int board[200001];
int dx[2] = { 1, -1};

int N, K;

int BFS() {
	queue<int> q;
	q.push(N);
	board[N] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir != 2)
				nx = cur + dx[dir];
			else
				nx = cur * 2;

			if (nx < 0 || nx > 100000)
				continue;

			int elapsedTime;
			if (dir != 2)
				elapsedTime = board[cur] + 1;
			else
				elapsedTime = board[cur];

			if (board[nx] == 0 || board[nx] > elapsedTime) {
				board[nx] = elapsedTime;
				q.push(nx);
			}

			if (nx == K)
				return board[nx] - 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	cout << BFS();

	//for (int i = 0; i < K + 10; i++) {
	//	cout << board[i] << ' ';
	//}
}