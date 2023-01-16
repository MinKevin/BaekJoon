#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int V, E, K;
vector<pair<int, int>> node[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int val[20001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		node[u].push_back({ v, w });
	}
	fill(&val[0], &val[V + 1], INT_MAX);
	val[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty()) {
		int x = pq.top().first;
		int U = pq.top().second;
		pq.pop();

		int min = INT_MAX;
		for (int i = 0; i < node[U].size(); i++) {
			int v = node[U][i].first;
			int w = node[U][i].second;
			if (x + w < min)
				min = x + w;
		}
		if (min < val[v]) {
			val[v] = x + w;
			pq.push(make_pair(x + w, v));
		}
	}

	for (int i = 1; i <= V; i++) {
		if (val[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << val[i] << '\n';
	}
}