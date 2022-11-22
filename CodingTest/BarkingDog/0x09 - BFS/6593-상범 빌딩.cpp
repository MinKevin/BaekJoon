#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

char board[30][30][30];
int vis[30][30][30];
int dx[6] = { 1, -1, 0, };
int dy[6] = { 0, 0, 1, -1, 0, };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int L, R, C;

queue<pair<pair<int, int>, int>> q;
vector<int> answer;

int BFS() {
	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.first.first + dz[dir];
			int nx = cur.first.second + dx[dir];
			int ny = cur.second + dy[dir];

			if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;

			if (board[nz][nx][ny] == '.' && vis[nz][nx][ny] == 0) {
				vis[nz][nx][ny] = vis[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ {nz, nx}, ny });
			}
			if (board[nz][nx][ny] == 'E') {
				return vis[cur.first.first][cur.first.second][cur.second];
			}
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> L >> R >> C;
		
		if (L == 0 && R == 0 && C == 0) 
			break;
		
		while (!q.empty()) {
			q.pop();
		}

		memset(vis, 0, sizeof(vis));
		//memset(vis, 0, L * R * C * sizeof(int));
		//fill(&vis[0][0][0], &vis[L - 1][R - 1][C], 0);

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> board[i][j];
				for (int k = 0; k < C; k++) {
					if (board[i][j][k] == 'S') {
						q.push(make_pair(make_pair(i, j), k));
						vis[i][j][k] = 1;
					}
				}
			}
			// cin 은 '\n' 이 몇개든 무시
			// 따라서 공백은 따로 처리해줄 필요가 없다.
		}

		answer.push_back(BFS());
	}
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << answer[i] << " minute(s).\n";
	}
}