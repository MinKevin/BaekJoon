#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1000001
int N, M, X;
vector<vector<pair<int, int>>> node;
vector<vector<int>> value;
void input() {
	cin >> N >> M >> X;

	node.resize(N + 1, vector<pair<int, int>>());
	value.resize(N + 1, vector<int>(N + 1, MAX));
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ cost, to });
	}
}

int solution() {
	for (int i = 1; i <= N; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.push({ 0, i });
		value[i][i] = 0;

		while (!pq.empty()) {
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (cost > value[i][cur])
				continue;

			for (int j = 0; j < node[cur].size(); j++) {
				int nCost = node[cur][j].first;
				int nxt = node[cur][j].second;

				if (value[i][nxt] > cost + nCost) {
					value[i][nxt] = cost + nCost;
					pq.push({ value[i][nxt], nxt });
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (ans < value[i][X] + value[X][i])
			ans = value[i][X] + value[X][i];
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}