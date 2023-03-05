#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
int dp[10001];

int solution() {
	for (int i = 0; i < N; i++) {
		int K, S;
		cin >> K >> S;
		for (int j = T; j >= K; j--) {
			dp[j] = max(dp[j], dp[j - K] + S);
		}
	}
	return dp[T];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> T;

	cout << solution();
}