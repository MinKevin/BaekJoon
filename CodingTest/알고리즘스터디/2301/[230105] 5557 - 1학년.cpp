#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector<int> v;
long long dp[101][21];

long long func() {
	dp[0][v[0]] = 1;
	for (int i = 1; i < v.size() - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] != 0) {
				if (j + v[i] <= 20) {
					dp[i][j + v[i]] += dp[i - 1][j];
				}
				if (j - v[i] >= 0) {
					dp[i][j - v[i]] += dp[i - 1][j];
				}
			}
		}
	}
	return dp[v.size() - 2][v[v.size() - 1]];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}


	cout << func() << '\n';
}