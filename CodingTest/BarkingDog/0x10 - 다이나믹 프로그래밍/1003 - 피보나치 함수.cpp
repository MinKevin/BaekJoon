#include <iostream>

using namespace std;

pair<int, int> dp[41];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	for (int i = 2; i <= 40; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}
	
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		cout << dp[input].first << ' ' << dp[input].second << '\n';
	}
}