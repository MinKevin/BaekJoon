#include <iostream>
#include <stack>

using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int, int>> S;
	vis[0][0] = 1;

	S.push({ 0, 0 });

	while (!S.empty()) {
		pair<int, int> cur = S.top(); S.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (vis[nx][ny] || board[nx][ny] != 1)
				continue;
			
			vis[nx][ny] = 1;
			S.push({ nx, ny });
		}
	}
}
