#include <iostream>
#include <queue>
#include <string>

using namespace std;
int r, c;
int arr[100][100];
int vis[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int sum, cntCheese, t;

string solution() {
	queue<pair<int, int>> present;
	queue<pair<int, int>> next;
	present.push({ 0, 0 });
	vis[0][0] = 1;
	while(sum != cntCheese) {
		t++;
		while (!present.empty()) {
			pair<int, int> cur = present.front();
			present.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c)
					continue;

				if (vis[nx][ny] == 0) {
					
					if (arr[nx][ny] == 0) {
						present.push({ nx, ny });
					}
					else {//arr[nx][ny] == 1
						next.push({ nx, ny });
						sum++;
					}
					vis[nx][ny] = 1;
				}
			}
		}
		present = next;
		while (!next.empty()) {
			next.pop();
		}
	}


	return to_string(t) + '\n' + to_string(present.size());
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	int inp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> inp;
			if (inp == 1)
				cntCheese++;
			arr[i][j] = inp;
		}
	}
	if (cntCheese == 0) {
		cout << 0 << '\n' << 0;
	}
	else {
		cout << solution();
	}
}