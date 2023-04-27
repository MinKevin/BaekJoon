#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;


int N, M, K;
vector<vector<pair<int, int>>> vertex;
vector<vector<long long>> dp;

void input() {
	cin >> N >> M >> K;
	vertex.resize(N + 1, vector<pair<int, int>>());
	dp.resize(N + 1, vector<long long>(K + 1, -1));

	int from, to, cost;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		vertex[from].push_back({ cost, to });
		vertex[to].push_back({ cost, from });
	}
}

ll solution() {
	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;//cost, pos, kCnt
	pq.push({0, 1, 0});
	dp[1][0] = 0;

	while (!pq.empty()) {
		tuple<long long, int, int> cur = pq.top();
		pq.pop();

		long long cost = get<0>(cur);
		int pos = get<1>(cur);
		int kCnt = get<2>(cur);

		if (dp[pos][kCnt] < cost)
			continue;

		for (int i = 0; i < vertex[pos].size(); i++) {
			ll addedCost = vertex[pos][i].first;
			int nxtVertex = vertex[pos][i].second;

			//도로를 포장하지 않는 경우
			if (dp[nxtVertex][kCnt] > cost + addedCost || dp[nxtVertex][kCnt] == -1) {
				dp[nxtVertex][kCnt] = cost + addedCost;
				pq.push({ dp[nxtVertex][kCnt], nxtVertex, kCnt });
			}

			//도로를 포장하는 경우
			if (kCnt < K) {
				if (dp[nxtVertex][kCnt + 1] > cost || dp[nxtVertex][kCnt + 1] == -1) {
					dp[nxtVertex][kCnt + 1] = cost;
					pq.push({ cost, nxtVertex, kCnt + 1 });
				}
			}
		}
	}
	long long ans = dp[N][0];
	for (int i = 0; i <= K; i++) {
		if (dp[N][i] == -1)
			break;
		ans = min(ans, dp[N][i]);
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}