#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int board[15][15];
int cnt = 0;

void Recur(int N, int x, int y) {
	if (N == 1) {
		if (x == r && y == c)
			cout << cnt << '\n';
		else
			cnt++;
		return;
	}
	if (x <= r && r < x + N && y <= c && c < y + N) {
		Recur(N / 2, x, y);
		Recur(N / 2, x, y + N / 2);
		Recur(N / 2, x + N / 2, y);
		Recur(N / 2, x + N / 2, y + N / 2);
	}
	else
		cnt += N * N;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;

	Recur(pow(2, N), 0, 0);
}