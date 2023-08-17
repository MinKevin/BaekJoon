#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> node;
vector<vector<pair<int, int>>> reverseNode;
vector<int> value;
vector<int> reverseValue;

void input() {
	cin >> N >> M >> X;

	node.resize(N + 1, vector<pair<int, int>>());
	reverseNode.resize(N + 1, vector<pair<int, int>>());
	value.resize(N + 1, INT_MAX);
	reverseValue.resize(N + 1, INT_MAX);

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({cost, to});
		reverseNode[to].push_back({ cost, from });
	}
}

void daijkstra(vector<vector<pair<int, int>>> &n, vector<int> &v) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, X });
	v[X] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < n[vertex].size(); i++) {
			int nCost = n[vertex][i].first;
			int nxtVertex = n[vertex][i].second;

			if (v[nxtVertex] > cost + nCost) {
				v[nxtVertex] = cost + nCost;
				pq.push({ v[nxtVertex], nxtVertex });
			}
		}
	}
}

int solution() {
	daijkstra(node, value);
	daijkstra(reverseNode, reverseValue);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		cout << value[i] << ' ' << reverseValue[i] << '\n';
		if (ans < value[i] + reverseValue[i])
			ans = value[i] + reverseValue[i];
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}