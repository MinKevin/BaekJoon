#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;
int ans[3];
int DFS(int N, int r, int c) {
	if (N == 1) {
		ans[board[r][c] + 1]++;
		return board[r][c];
	}

	int buf[4] = { 0, };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			buf[DFS(N / 3, r + N / 3 * i, c + N / 3 * j) + 1]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (buf[i] == 9) {
			ans[i] -= 8;
			return i - 1;
		}
	}
	return 2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	board.resize(N, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int buf;
			cin >> buf;
			board[i].push_back(buf);
		}
	}

	DFS(N, 0, 0);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << '\n';
	}
}