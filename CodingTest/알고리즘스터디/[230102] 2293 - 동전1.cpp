#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;
int dp[10001];

void func() {
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= k; j++) {
			dp[j] += dp[j - v[i]];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	func();
	cout << dp[k];
}