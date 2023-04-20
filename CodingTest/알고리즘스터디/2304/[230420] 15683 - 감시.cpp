#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int board[8][8];
int vis[8][8];
vector<pair<int, int>> cctv;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ans, wall;
vector<vector<vector<int>>> direction;

void recur(int c, int sum) {
	if (c == cctv.size()) {
		//cout << '\n';
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << vis[i][j];
		//	}
		//	cout << '\n';
		//}

		if (ans < sum)
			ans = sum;
		return;
	}
	queue<pair<int, int>> changed;
	pair<int, int> cur = cctv[c];
	int pst = board[cur.first][cur.second];
	for (int i = 0; i < direction[pst].size(); i++) {
		for (int j = 0; j < direction[pst][i].size(); j++) {
			int x = cur.first;
			int y = cur.second;
			while (true) {
				int nx = x + dx[direction[pst][i][j]];
				int ny = y + dy[direction[pst][i][j]];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M || board[nx][ny] == 6)
					break;
				if (vis[nx][ny] == 0) {
					vis[nx][ny] = 1;
					changed.push({ nx, ny });
					sum++;
					//cout << nx << ' ' << ny << '\n';
				}
				x = nx; y = ny;
			}
		}
			recur(c + 1, sum);
			sum -= changed.size();
		
		while (!changed.empty()) {
			pair<int, int> cur = changed.front();
			changed.pop();
			vis[cur.first][cur.second] = 0;
		}
	}
}


int solution() {
	direction.resize(6, vector<vector<int>>());
	direction[1].push_back(vector<int>({ 1 }));
	direction[1].push_back(vector<int>({ 2 }));
	direction[1].push_back(vector<int>({ 3 }));
	direction[1].push_back(vector<int>({ 0 }));

	direction[2].push_back(vector<int>({ 0, 1 }));
	direction[2].push_back(vector<int>({ 2, 3 }));

	direction[3].push_back(vector<int>({ 0, 2 }));
	direction[3].push_back(vector<int>({ 0, 3 }));
	direction[3].push_back(vector<int>({ 1, 2 }));
	direction[3].push_back(vector<int>({ 1, 3 }));

	direction[4].push_back(vector<int>({ 1, 2, 3 }));
	direction[4].push_back(vector<int>({ 0, 2, 3 }));
	direction[4].push_back(vector<int>({ 0, 1, 3 }));
	direction[4].push_back(vector<int>({ 0, 1, 2 }));

	direction[5].push_back(vector<int>({ 1, 2, 3, 0 }));

	recur(0, cctv.size());

	return N * M  - wall - ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int inp;
			cin >> inp;
			if (inp != 0) {
				if (inp != 6) {
					cctv.push_back({ i, j });
					vis[i][j] = 1;
				}
				else {
					wall++;
				}
			}
			board[i][j] = inp;
		}
	}

	cout << solution();
}