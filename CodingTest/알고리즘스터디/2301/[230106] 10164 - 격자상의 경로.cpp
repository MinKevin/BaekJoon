#include <iostream>
#include <vector>
using namespace std;

int  N, M, K, x, y;

vector<vector<int>> board;

int func(int x, int y) {
	board[0][0] = 1;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (i - 1 >= 0)
				board[i][j] += board[i - 1][j];
			if (j - 1 >= 0)
				board[i][j] += board[i][j - 1];
		}
	}

	for (int i = x; i < N; i++) {
		for (int j = y; j < M; j++) {
			if (i - 1 >= x)
				board[i][j] += board[i - 1][j];
			if (j - 1 >= y)
				board[i][j] += board[i][j - 1];
		}
	}
	return board[N - 1][M - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	board = vector<vector<int>>(N, vector<int>(M, 0));

	if (K == 0) {
		x == N - 1;
		y == M - 1;
	}
	else {
		x = (K - 1) / M;
		y = (K - 1) % M;
	}
	cout << func(x, y);
}