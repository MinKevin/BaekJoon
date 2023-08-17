#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int V, E, K;
vector<int> value;
vector<vector<pair<int, int>>> node;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void input() {
	cin >> V >> E >> K;
	value.resize(V + 1, INT_MAX);
	node.resize(V + 1, vector<pair<int, int>>());

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back(make_pair(w, v));
	}
}

void solution() {
	value[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty()) {
		int costSum = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[cur].size(); i++) {
			int cost = node[cur][i].first;
			int nextNode = node[cur][i].second;

			if (value[nextNode] > costSum + cost) {
				value[nextNode] = costSum + cost;
				pq.push({ value[nextNode], nextNode });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (value[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << value[i] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}