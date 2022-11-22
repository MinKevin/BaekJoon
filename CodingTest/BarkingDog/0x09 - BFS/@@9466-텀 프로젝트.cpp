#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int board[100001];

//{cnt, startNum}
pair<int, int> vis[100001];

int T, n, cnt;
vector<int> answer;

//팀을 이룬 사람을 count
int DFS(int odr, int count, int startNum) {
	if (vis[odr] != make_pair(0, 0)) {
		if (vis[odr].second == startNum)
			return count - vis[odr].first;

		else
			return 0;
	}

	vis[odr] = {count, startNum };

	return DFS(board[odr], count + 1, startNum);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));

		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> board[i];
		
		for (int i = 1; i <= n; i++) {
			if (vis[i] == make_pair(0, 0)) {
				cnt += DFS(i, 1, i);
			}
		}

		answer.push_back(n - cnt);
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
}