#include <iostream>
#include <math.h>

using namespace std;

int dp[1000001];
int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	cout << dp[n];
}
