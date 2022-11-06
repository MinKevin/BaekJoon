#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int answer[3];

int func(int N, int r, int c) {
	if (N == 1) {
		answer[board[r][c] + 1]++;
		return board[r][c] + 1;
	}
	bool cantOne = false;
	int count[3];
	memset(count, 0, sizeof(count));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int buf = func(N / 3, r + N / 3 * i, c + N / 3 * j);
			if (buf != -1)
				count[buf]++;
			else
				cantOne = true;
		}
	}
	if (cantOne == false)
		for (int i = 0; i < 3; i++) {
			if (count[i] == 9) {
				answer[i] -= 8;
				return i;
			}
		}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> board;
	cin >> N;
	board.resize(N, vector<int>(0, 0));

	int numBuf;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> numBuf;
			board[i].push_back(numBuf);
		}

	func(N, 0, 0);

	for (int i = 0; i < 3; i++)
		cout << answer[i] << '\n';
}
