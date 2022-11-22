//3 3 10
//011
//011
//000
//
//같은 경우에 시작점->하->하->우->우 로 방문할 수 있으나
//본 코드로 실행하면 오답이 나옵니다.
//최단 경로에 대한 내용을 생각해봐야 할 것 같아용

#include <iostream>
#include <queue>

using namespace std;

struct P {
	int x = 0;
	int y = 0;
	int breakingWall = 0;
	bool isNight = false;
	int cnt = 1;
};

struct compare {
	bool operator()(const P& s1, const P& s2) {
		return s1.cnt > s2.cnt;
	}
};

int board[1000][1000];
int vis[1000][1000][11];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

priority_queue<P, vector<P>, compare> q;

int N, M, K;

void input() {
	cin >> N >> M >> K;

	string buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		for (int j = 0; j < M; j++) {
			board[i][j] = buf[j] - '0';
		}
	}
}

int BFS() {
	if (N == 1 && M == 1)
		return 1;

	vis[0][0][0] = 1;

	P temp;

	q.push(temp);

	while (!q.empty()) {
		P cur = q.top();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (nx == N - 1 && ny == M - 1) {
				return cur.cnt + 1;
			}

			if (board[nx][ny] == 1 && cur.breakingWall < K && vis[nx][ny][cur.breakingWall + 1] == 0) {
				if (cur.isNight == false) {
					vis[nx][ny][cur.breakingWall + 1] = 1;
					q.push({ nx, ny, cur.breakingWall + 1, !cur.isNight, cur.cnt + 1});
				}
				else {
					vis[nx][ny][cur.breakingWall + 1] = 1;
					q.push({ nx, ny, cur.breakingWall + 1, cur.isNight, cur.cnt + 2});
				}
			}

			if (board[nx][ny] == 0 && vis[nx][ny][cur.breakingWall] == 0) {
				vis[nx][ny][cur.breakingWall] = 1;
				q.push({ nx, ny, cur.breakingWall, !cur.isNight, cur.cnt + 1});
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << BFS();
}
