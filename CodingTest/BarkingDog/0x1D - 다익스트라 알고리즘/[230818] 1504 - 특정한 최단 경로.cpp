#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1600001

using namespace std;

int N, E;
vector<vector<pair<int, int>>> node;
int v1, v2;

//st에서 en까지의 최단 경로 반환
int dijkstra(int st, int en) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> value = vector<int>(N + 1, INF);
	pq.push({ 0, st });
	value[st] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[vertex].size(); i++) {
			int nCost = node[vertex][i].first;
			int nxtVertex = node[vertex][i].second;

			if (value[nxtVertex] > cost + nCost) {
				value[nxtVertex] = cost + nCost;
				pq.push({ value[nxtVertex], nxtVertex });
			}
		}
	}
	return value[en];
}

void input() {
	cin >> N >> E;
	node.resize(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ c, b });
		node[b].push_back({ c, a });
	}
	cin >> v1 >> v2;
}

int solution() {
	int ans = INF;
	ans = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N),
		dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N));
	if (ans >= INF)
		return -1;
	else
		return ans;
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}