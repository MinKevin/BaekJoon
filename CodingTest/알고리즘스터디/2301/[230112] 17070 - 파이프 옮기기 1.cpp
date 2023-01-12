/*
Time : 1시간 30분정도...?
Comment : dfs(int X, int Y, int dir(dir == 놓인 모양))으로 풀 수 있는 방법이 있다.
변수를 최소화해서 사용할 수 있다.
그 방법으로 다시 풀어보자.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[16][16];
//3차원의 0:가로 1:세로 2:대각선
int dp[16][16][3];

//0~1 가로
//2~3 세로
//4~6 대각선
//이동 모양이 대각선일 때의 index = 1, 3, 6;
int dx[7] = {0, 1, 1, 1, 0, 1, 1};
int dy[7] = {1, 1, 0, 1, 1, 0, 1};

int dfs(int stX, int stY, int enX, int enY) {
	//cout << stX << ' ' << stY << ' ' << enX << ' ' << enY << '\n';
	if (enX == N - 1 && enY == N - 1) {
		return 1;
	}
	//0:가로 1:세로 2:대각선
	int shape;
	int st, en;
	int shapeX = enX - stX;
	int shapeY = enY - stY;
	if (shapeX == 0 && shapeY == 1) {
		shape = 0;
		st = 0;
		en = 1;
	}
	else if (shapeX == 1 && shapeY == 0) {
		shape = 1;
		st = 2;
		en = 3;
	}
	else if (shapeX == 1 && shapeY == 1) {
		shape = 2;
		st = 4;
		en = 6;
	}

	if (dp[enX][enY][shape] != -1) {
		return dp[enX][enY][shape];
	}

	dp[enX][enY][shape] = 0;
	for (int dir = st; dir <= en; dir++) {
		int nx = enX + dx[dir];
		int ny = enY + dy[dir];

		if (nx >= N || ny >= N)
			continue;
		
		if ((dir == 1 || dir == 3 || dir == 6) && board[nx][ny] == 0 && board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0 ||
			(dir != 1 && dir != 3 && dir != 6 && board[nx][ny] == 0)) {
			dp[enX][enY][shape] += dfs(enX, enY, nx, ny);
		}
	}
	return dp[enX][enY][shape];
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	fill(&dp[0][0][0], &dp[15][15][3], -1);
	dfs(0, 0, 0, 1);	
	cout << dp[0][1][0];
}