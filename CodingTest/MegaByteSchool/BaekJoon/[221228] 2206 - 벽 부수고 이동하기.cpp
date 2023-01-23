/*
Date : 22.12.28
Time : 5:10 ~ 5:43
Comment : 
	근데 이런거 코테 나오면 못 풀 것 같다... 반례를 못 찾을 듯
*/

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int N, M;
string board[1000];
int vis[1000][1000][2];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void BFS() {
	if (N == 1 && M == 1) {
		cout << 1;
		return;
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0 ,0, 0 });
	vis[0][0][0] = 1;

	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (nx == N - 1 && ny == M - 1) {
				cout << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				return;
			}

			if (board[nx][ny] == '0' && vis[nx][ny][get<2>(cur)] == 0) {
				vis[nx][ny][get<2>(cur)] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push({ nx, ny, get<2>(cur) });
			}

			else if (board[nx][ny] == '1' && get<2>(cur) == 0) {
				vis[nx][ny][1] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}
	cout << -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	BFS();
}