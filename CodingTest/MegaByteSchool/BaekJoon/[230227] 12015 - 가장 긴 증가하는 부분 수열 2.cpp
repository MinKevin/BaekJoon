#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> dp;
int solution() {
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dp.resize(n, 1);
	int inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		v.push_back(inp);
	}
}