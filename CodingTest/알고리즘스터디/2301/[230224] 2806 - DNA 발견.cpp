#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string inp;
vector<vector<int>> dp;

int solution() {
	dp.resize(2, vector<int>(N, 0));
	if (inp[0] == 'A') {
		dp[0][0] = 0;
		dp[1][0] = 1;
	}
	else {
		dp[0][0] = 1;
		dp[1][0] = 0;
	}

	for (int i = 1; i < N; i++) {
		if (inp[i] == 'A') {
			dp[0][i] = dp[0][i - 1];
			dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);
		}
		else {
			dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);
			dp[1][i] = dp[1][i - 1];
		}
	}

	return dp[0][N - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> inp;

	cout << solution();
}
