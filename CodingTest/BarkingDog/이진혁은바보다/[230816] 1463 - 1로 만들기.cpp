#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int N;
vector<int> dp;
void input() {
	cin >> N;
	dp.resize(N + 1, INT_MAX);
}

int solution() {
	queue<int> q;
	//pair => (cnt, currentValue)
	q.push(N);
	dp[N] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == 1)
			return dp[1];

		// -1
		if (dp[cur - 1] > dp[cur] + 1) {
			q.push(cur - 1);
			dp[cur - 1] = dp[cur] + 1;	
		}

		// / 2
		if (cur % 2 == 0 && dp[cur / 2] > dp[cur] + 1) {
			q.push(cur / 2);
			dp[cur / 2] = dp[cur] + 1;
		}
		
		// / 3
		if (cur % 3 == 0 && dp[cur / 3] > dp[cur] + 1) {
			q.push(cur / 3);
			dp[cur / 3] = dp[cur] + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}