#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[12];
int dx[3] = { 1, 2, 3 };
vector<int> answer;
int T, n;

//1번 풀이
int func() {
	cin >> n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int dir = 0; dir < 3; dir++) {
			int nx = i - dx[dir];

			if (nx < 0)
				continue;

			dp[i] += dp[nx];
		}
	}
	return dp[n];
}


//2번 풀이
int func2() {
	cin >> n;
	memset(dp, 0, sizeof(dp));
	dp[1] = 1, dp[2] = 2, dp[3] = 4;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[n];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		answer.push_back(func());
	}

	for (auto v : answer)
		cout << v << '\n';
}