//이전에는 vis 배열을 생성하지 않고, board에서 접근한 칸을 1로 바꿔주는 식으로 접근 했다.
//메모리 측면에서 이전에 했던 방식이 훨씬 효율적인 것 같다.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[100][100];
int vis[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int M, N, K;
vector<int> answer;

int BFS() {
	int cnt = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0 && vis[i][j] == 0) {
				vis[i][j] = 1;
				q.push(make_pair(i, j));
				cnt++;

				int width = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;

						if (board[nx][ny] == 0 && vis[nx][ny] == 0) {
							vis[nx][ny] = 1;
							q.push({ nx, ny });
							width++;
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

	cin >> M >> N >> K;

	int x1, x2, y1, y2;

	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) 
			for (int j = y1; j < y2; j++) 
				board[i][j] = 1;
	}
	cout << BFS() << '\n';

	sort(begin(answer), end(answer), less<>());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
}