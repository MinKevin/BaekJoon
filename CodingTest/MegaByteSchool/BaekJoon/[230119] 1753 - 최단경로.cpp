#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
#define INF 987654321
using namespace std;

int V, E, K;
vector<pair<int, int>> node[20001];
int value[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void daijkstra() {
	value[K] = 0;
	pq.push({ 0, K });
	
	while (!pq.empty()) {
		int disSum = pq.top().first;
		int nextNode = pq.top().second;
		pq.pop();

		int w, v;
		for (int i = 0; i < node[nextNode].size(); i++) {
			w = node[nextNode][i].first;
			v = node[nextNode][i].second;

			if (value[v] > disSum + w) {
				value[v] = disSum + w;
				pq.push({ disSum + w, v });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		node[u].push_back({ w, v });
	}
	fill(&value[0], &value[V + 1], INF);
	
	daijkstra();

	for (int i = 1; i <= V; i++) {
		if (value[i] != INF)
			cout << value[i] << '\n';
		else
			cout << "INF\n";
	}
}