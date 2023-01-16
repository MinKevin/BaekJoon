#include <iostream>
#include <algorithm>

using namespace std;

int n;
int triangle[500][500];
int dp[500][500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];

	int answer = dp[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int max1 = 0;
			int max2 = 0;
			if (j - 1 >= 0)
				max1 = dp[i - 1][j - 1];
			if (j <= i - 1)
				max2 = dp[i - 1][j];
			//cout << max1 << ' ' << max2 << '\n';
			dp[i][j] = max(max1, max2) + triangle[i][j];
			if (dp[i][j] > answer)
				answer = dp[i][j];
		}
	}

	cout << answer;
}