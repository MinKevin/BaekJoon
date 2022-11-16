#include <iostream>

using namespace std;

char bufBoard[8][7];
int board[8][7];
char vis[8][7];
int domino[7][7];
int answer;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void func(int r, int c, int usedDomino) {
	for (int dir = 0; dir < 2; dir++) {
		int nx = r + dx[dir];
		int ny = c + dy[dir];

		if (nx < 0 || ny < 0 || nx >= 8 || ny >= 7)
			continue;

		pair<int, int> dominoNum;
		if (board[r][c] > board[nx][ny])
			dominoNum = { board[nx][ny], board[r][c] };
		else
			dominoNum = { board[r][c], board[nx][ny] };

		if (domino[dominoNum.first][dominoNum.second] == 1 && vis[nx][ny] == 0) {
			domino[dominoNum.first][dominoNum.second] = 0;
			vis[r][c] = 1;
			vis[nx][ny] = 1;

			for (int i = r * 7 + c + 1; i < r * 7 + c + 14; i++) {
				if (i >= 56)
					break;

				if (usedDomino == 27) {
					answer++;
					break;
				}

				if (i / 7 >= 8 || i % 7 >= 7)
					break;

				if (vis[i / 7][i % 7] == 0) {
					//cout << dominoNum.first << ' ' << dominoNum.second << ' ' << usedDomino + 1 << '\n';
					func(i / 7, i % 7, usedDomino + 1);
					break;
				}
			}
			domino[dominoNum.first][dominoNum.second] = 1;
			vis[r][c] = 0;
			vis[nx][ny] = 0;
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 8; i++) 
		cin >> bufBoard[i];

	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 7; j++) 
			board[i][j] = bufBoard[i][j] - '0';

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i > j)
				continue;
			domino[i][j] = 1;
		}
	}

	func(0, 0, 0);

	cout << answer;
}