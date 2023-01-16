#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> dp;
	cin >> N >> M;
	dp.assign(N + 1, 0);
	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		if (i == 1) {
			dp[1] = input;
		}
		else {
			dp[i] = dp[i - 1] + input;
		}
	}

	int st, en;
	for (int i = 0; i < M; i++) {
		cin >> st >> en;
		cout << dp[en] - dp[st - 1] << '\n';
	}
}