#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<vector<int>> v;
int dp[1000][3];
int func() {
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
	}
	//algorithm header
	return min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v.assign(N, vector<int>(3, 0));
	for (int i = 0; i < N; i++) {
		cin >>  v[i][0] >> v[i][1] >> v[i][2];
	}

	cout << func();
}