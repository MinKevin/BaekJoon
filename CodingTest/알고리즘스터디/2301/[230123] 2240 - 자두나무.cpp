#include <iostream>

using namespace std;

int T, W;
int ans[1001][2][32];
int board[1001];

/*
ans[i][0][k] = max(ans[i - 1][0][k] + 1, ans[i - 1][1][k - 1] + 1;
ans[i][1][k] = max(ans[i - 1][1][k] + 1, ans[i - 1][0][k - 1] + 1;
*/

void func() {
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= W + 1; j++) {
			if (board[i] == 1) {
				ans[i][0][j] = max(ans[i - 1][0][j] + 1, ans[i - 1][1][j - 1] + 1);
				ans[i][1][j] = ans[i - 1][1][j];
			}
			else {
				if (i == 1 && j == 1)
					continue;
				ans[i][0][j] = ans[i - 1][0][j];
				ans[i][1][j] = max(ans[i - 1][1][j] + 1, ans[i - 1][0][j - 1] + 1);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> W;

	for (int i = 1; i <= T; i++)
		cin >> board[i];

	func();

	int answer = 0;
	for (int i = 1; i <= W + 1; i++) {
		for (int j = 0; j < 2; j++) {
			//cout << ans[T][j][i] << ' ';
			if (answer < ans[T][j][i])
				answer = ans[T][j][i];
		}
	}
	cout << answer;
}