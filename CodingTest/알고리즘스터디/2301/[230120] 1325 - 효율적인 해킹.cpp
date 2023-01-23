#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<int> board[10001];
int vis[10001];
int dp[10001];
int maxCnt = 0;

int func(int target) {
	vis[target] = 1;
	int answer = 1;
	queue<int> q;
	for (int i = 0; i < board[target].size(); i++) {
		if (vis[board[target][i]] == 0) {
			vis[board[target][i]] = 1;
			q.push(board[target][i]);
			answer++;
		}
		
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < board[cur].size(); i++) {
			if (vis[board[cur][i]] == 0) {
				vis[board[cur][i]] = 1;
				q.push(board[cur][i]);
				answer++;
			}
		}
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		board[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		if (board[i].size() != 0) {
			dp[i] = func(i);
			if (dp[i] > maxCnt)
				maxCnt = dp[i];
			memset(vis, 0, (N + 1) * 4);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] == maxCnt)
			cout << i << ' ';
	}
}