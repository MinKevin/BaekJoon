/*
Date : 22.12.06
Time : 00:48
Comment : 
	43번째 줄의 주석 확인
	35번째 줄의 for(int dir = 0; dir <4; dir++)와 45번째 줄을 합하여,
	if 문 4개로 필요한 위치만 유효성 검사를 진행 시, 시간을 크게 줄일 수 있음
 
example
3 3
1 1 1
1 1 1
1 1 1
*/

#include <iostream>

using namespace std;

int N, M;
int board[5][5];
int mask[5][5];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int distance_;

void dfs(int cur, int sum) {
	if (cur == N * M) {
		if (distance < sum)
			distance_ = sum;
		return;
	}

	if (mask[cur / M][cur % M] == 0) {
		for (int dir = 0; dir < 4; dir++) {

			int nx1 = cur / M + dx[dir];
			int ny1 = cur % M + dy[dir];

			int nxtDir = dir + 1 == 4 ? 0 : dir + 1;
			int nx2 = cur / M + dx[nxtDir];
			int ny2 = cur % M + dy[nxtDir];

			//이 부분을 방향에 맞춘 검사로 수정 시 최적화 가능
			if (nx1 < 0 || ny1 < 0 || nx1 >= N || ny1 >= M || nx2 < 0 || ny2 < 0 || nx2 >= N || ny2 >= M)
				continue;

			if (mask[nx1][ny1] == 1 || mask[nx2][ny2] == 1)
				continue;

			sum += board[cur / M][cur % M] * 2 + board[nx1][ny1] + board[nx2][ny2];
			mask[cur / M][cur % M] = mask[nx1][ny1] = mask[nx2][ny2] = 1;

			/*
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << vis[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << sum << '\n';
			*/

			dfs(cur + 1, sum);

			mask[cur / M][cur % M] = mask[nx1][ny1] = mask[nx2][ny2] = 0;
			sum -= board[cur / M][cur % M] * 2 + board[nx1][ny1] + board[nx2][ny2];
		}
	}
	//해당 위치를 비워두고 다음으로 진행
	dfs(cur + 1, sum);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	dfs(0, 0);

	cout << distance_;
}