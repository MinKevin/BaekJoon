#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int T, K;
int board[501];
int dp[501][501];
int cumulativeSum[501];
vector<int> ans;

int recur(int st, int end) {
	if (end - st == 1) {
		dp[st][end] = board[st] + board[end];
		return dp[st][end];
	}
	else if (st == end) {
		return 0;
	}
	else if (dp[st][end] != 0)
		return dp[st][end];

	int ans = INT_MAX;
	for (int i = 0; i < end - st; i++) {
		int result = recur(st, st + i) + recur(st + i + 1, end);
		ans = min(ans, result);
	}
	dp[st][end] = ans + cumulativeSum[end] - (st > 0 ? cumulativeSum[st - 1] : 0);
	return dp[st][end];
}

void solution() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> board[i];
		if (i == 0) {
			cumulativeSum[0] = board[0];
		}
		else {
			cumulativeSum[i] = cumulativeSum[i - 1] + board[i];
		}
	}

	fill(&dp[0][0], &dp[K - 1][K], 0);

	ans.push_back(recur(0, K - 1));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		solution();
	}
	
	for (auto v : ans)
		cout << v << '\n';
}