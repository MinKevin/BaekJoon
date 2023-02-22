#include <iostream>
#include <algorithm> 
using namespace std;

int xLoc[5][4] = {
	{0, 0, 0, 0},
	{0, 0, 1, 1},
	{0, 1, 2, 2},
	{0, 1, 1, 2},
	{0, 0, 0, 1}
};
int yLoc[5][4] = {
	{0, 1, 2, 3},
	{0, 1, 0, 1},
	{0, 0, 0, 1},
	{0, 0, 1, 1},
	{0, 1, 2, 1}
};

int dx[4] = { 1, -1, 1, -1 };
int dy[4] = { 1, 1, -1, -1 };

int n, m, arr[500][500], ans;

int func(int x, int y) {
	int num = 0;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nx = x + xLoc[i][j] * dx[k];
				int ny = y + yLoc[i][j] * dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
					cnt = 0;
					break;
				}
				else {
					cnt += arr[nx][ny];
				}
			}
			num = max(num, cnt);
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nx = x + yLoc[i][j] * dx[k];
				int ny = y + xLoc[i][j] * dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
					cnt = 0;
					break;
				}
				else {
					cnt += arr[nx][ny];
				}
			}
			num = max(num, cnt);
		}
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, func(i, j));
		}
	}

	cout << ans;
}