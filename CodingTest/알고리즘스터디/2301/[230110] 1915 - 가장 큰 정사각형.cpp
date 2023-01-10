#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[1001][1001];

int dp() {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1) {
				board[i][j] = min({ board[i][j - 1], board[i - 1][j - 1], board[i - 1][j] }) + 1;
				if (board[i][j] > answer)
					answer = board[i][j];
			}
		}
	}

	return answer * answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	string input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j + 1] = input[j] - '0';
		}
	}

	cout << dp() << '\n';
}