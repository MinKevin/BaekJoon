#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
int board[20][20];
bool mask[20];
int answer = 0x7FFFFFFF;

int calculateStats() {
	int homeStats = 0;
	int awayStats = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!mask[i] && !mask[j]) {
				awayStats += board[i][j] + board[j][i];
			}
			else if (mask[i] && mask[j]) {
				homeStats += board[i][j] + board[j][i];
			}
		}
	}
	return abs(homeStats - awayStats);
}

void dfs(int idx, int cnt) {
	if (cnt > N / 2)
		return;

	if (idx != 0)
		answer = min(calculateStats(), answer);

	for (int i = idx; i < N; i++) {
		mask[i] = true;
		dfs(i + 1, cnt + 1);
		mask[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0);

	cout << answer;
}