#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> board;

void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] += board[i - 1][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] += board[i][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	board.resize(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	solution();
}