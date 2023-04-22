#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int board[128][128];
int ans[2];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

int recur(int x, int y, int length) {
	if (length == 1)
		return board[x][y];

	int buf[3] = { 0, };
	for (int dx = 0; dx < 2; dx++) {
		for (int dy = 0; dy < 2; dy++) {
			buf[recur(x + length/2 * dx, y + length/2 * dy, length/2)]++;
		}
	}

	for (int i = 0; i < 2; i++) {
		if (buf[i] == 4)
			return i;
		ans[i] += buf[i];
	}
	return 2;
}

string solution() {
	int result = recur(0, 0, N);
	if (result != 2)
		ans[result]++;

	return to_string(ans[0]) + '\n' + to_string(ans[1]);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}