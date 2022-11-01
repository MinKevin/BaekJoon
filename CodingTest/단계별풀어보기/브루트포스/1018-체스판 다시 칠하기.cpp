#include <iostream>

#define min(a, b) a < b ? a : b

using namespace std;

int N, M;
char board[51][51]; 
int answer = 64;

int BruteForce() {
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			char expectedColor;
			int cnt = 0;
			expectedColor = board[i][j];
			//a
			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					if (expectedColor != board[x][y]) 
						cnt++;
					if (y != j + 7)
					expectedColor = expectedColor == 'B' ? 'W' : 'B';
				}
			}
			//a

			//b
			if (cnt > 32)
				cnt = 64 - cnt;
			//b

			//c
			answer = min(answer, cnt);
			//c
		}
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
			cin >> board[i];
	}
	
	cout << BruteForce();
}