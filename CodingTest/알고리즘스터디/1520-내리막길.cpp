#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> dp;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int M, N, H;

int DFS(int row, int col, int targetRow, int targetCol) {
	if (row == targetRow && col == targetCol)
		return 1;

	if (dp[row][col] != -1)
		return dp[row][col];

	dp[row][col] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = row + dx[dir];
		int ny = col + dy[dir];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;

		if (board[nx][ny] < board[row][col]) {
			dp[row][col] += DFS(nx, ny, targetRow, targetCol);
		}
	}
	
	return dp[row][col];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	board.assign(M, vector<int>(N, 0));
	dp.assign(M, vector<int>(N, -1));

	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			cin >> board[i][j];
		
	H = DFS(0, 0, M -1, N - 1);
	cout << H;
}