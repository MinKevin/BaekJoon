#include <iostream>
#include <vector>

using namespace std;

int T, k;
vector<pair<int, int>> v;
int dp[10001];
int solution() {
	dp[0] = 1;
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < k; j++) {
			dp[i] += dp[i - j];
		}
	}


	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T >> k;

	int p, n;
	for (int i = 0; i < k; i++) {
		cin >> p >> n;
		v.push_back({ p, n });
	}

	cout << solution();
}