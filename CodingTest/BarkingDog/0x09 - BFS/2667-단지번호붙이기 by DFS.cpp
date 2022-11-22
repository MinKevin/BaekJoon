#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[25][25];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, result, cnt;
vector<int> answer;

void DFS(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;

		if (board[nr][nc] == 1) {
			board[nr][nc] = 0;
			cnt++;
			DFS(nr, nc);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		for (int j = 0; j < buf.size(); j++)
			board[i][j] = buf[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) {
				board[i][j] = 0;
				result++;
				cnt = 1;
				DFS(i, j);
				answer.push_back(cnt);
			}
		}
	}

	cout << result << '\n';

	sort(begin(answer), end(answer), less<>());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}