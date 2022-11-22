#include <iostream>
#include <vector>

using namespace std;

int answer[3];
vector<vector<int>> board;

int func(int N, int x, int y) {
	if (N == 1) {
		answer[board[x][y] + 1]++;
		return board[x][y] + 1;
	}
	int count[3] = { 0, };
	bool cantOne = false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			int buf = func(N / 3, x + N / 3 * i, y + N / 3 * j);
			if (buf != -1)
				count[buf]++;
			else
				cantOne = true;
		}
	if (cantOne == false)
		for (int i = 0; i < 3; i++)
			if (count[i] == 9) {
				answer[i] -= 8;
				return i;
			}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	board.resize(N, vector<int>(N, 0));
	//board.resize(N, vector<int>(0, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			/*int buf;
			cin >> buf;
			board[i].push_back(buf);*/
		}
	}
	func(N, 0, 0);

	for (int i = 0; i < 3; i++)
		cout << answer[i] << '\n';
}