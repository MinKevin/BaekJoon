#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[10001];
int N, ansMax;
vector<vector<pair<int, int>>> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v.assign(N + 1, vector<pair<int, int>>());

	int requiredTime;
	int cnt;
	for (int i = 0; i < N; i++) {
		cin >> requiredTime;
		cin >> cnt;

		int buf;
		if (cnt == 0) {
			v[0].push_back({ i + 1, requiredTime });
		}
		else {
			for (int j = 0; j < cnt; j++) {
				cin >> buf;
				v[buf].push_back({ i + 1, requiredTime });
			}
		}
		
		
	}


	// 1 2 3 4  5  6  7
	// 5 6 9 11 12 19 23
	fill(&dp[1], &dp[10001], 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int maxBuf = dp[i] + v[i][j].second;
			if (dp[v[i][j].first] < dp[i] + v[i][j].second) {
				dp[v[i][j].first] = dp[i] + v[i][j].second;
			}

			if (maxBuf > ansMax)
				ansMax = maxBuf;
		}
	}

	cout << ansMax << '\n';
	for (int i = 0; i <= N; i++) {
		cout << dp[i] << ' ';
	}
}