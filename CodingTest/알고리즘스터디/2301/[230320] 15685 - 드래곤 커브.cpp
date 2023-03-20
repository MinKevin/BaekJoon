#include <iostream>
#include <vector>

using namespace std;

//cos -sin  0 -1
//sin cos  1 0

int N;
int x, y, d, g;
int ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int vis[101][101];
vector<pair<int, int>> coord;

void solution() {
	for (int i = 0; i < g; i++) {
		int centerX = coord.back().first, centerY = coord.back().second;
		int trial = coord.size() - 2;
		for (int i = trial; i >= 0; i--) {
			int a = coord[i].first, b = coord[i].second;
			int na = -1 * (b - centerY) + centerX;
			int nb = (a - centerX) + centerY;
			if (na < 0 || nb < 0 || na > 100 || nb > 100) {
				continue;
			}
			coord.push_back({ na, nb });
			vis[na][nb] = 1;
			//cout << na << ' ' << nb << '\n';
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		coord = vector<pair<int, int>>();
		cin >> x >> y >> d >> g;
		coord.push_back({ x, y });
		coord.push_back({ x + dx[d], y + dy[d] });
		vis[x][y] = 1;
		vis[x + dx[d]][y + dy[d]] = 1;
		solution();
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (vis[i][j] == 1 && vis[i + 1][j] == 1 && vis[i][j + 1] == 1 && vis[i + 1][j + 1] == 1)
				ans++;
		}
	}

	cout << ans;
}