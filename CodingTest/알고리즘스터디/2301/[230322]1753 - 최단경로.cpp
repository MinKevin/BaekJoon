#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int V, E, K;
vector<int> value;
vector<vector<pair<int, int>>> node;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void solution() {
	value[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty()) {
		int disSum = pq.top().first;
		int nextNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[nextNode].size(); i++) {
			int w = node[nextNode][i].first;
			int v = node[nextNode][i].second;

			if (value[v] > disSum + w) {
				value[v] = disSum + w;
				pq.push({ disSum + w, v });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (value[i] != INT_MAX)
			cout << value[i] << '\n';
		else
			cout << "INF\n";
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> K;

	value.resize(V + 1, INT_MAX);
	node.resize(V + 1, vector<pair<int, int>>());

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		node[u].push_back({ w, v });
	}

	solution();
}