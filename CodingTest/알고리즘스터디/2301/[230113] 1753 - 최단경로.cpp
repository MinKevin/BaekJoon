#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define INF 987654321

using namespace std;

int V, E, K;
vector<pair<int, int>> node[20005];
int val[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++) {
		val[i] = INT_MAX;
	}
	val[K] = 0;
	pq.push(make_pair(K, 0));

	while (!pq.empty()) {
		int loc = pq.top().first;
		int sumDis = pq.top().second;
		pq.pop();
		cout << loc << ' ' << sumDis << '\n';
		for (int i = 0; i < node[loc].size(); i++) {
			int nextLoc = node[loc][i].first;
			int w = node[loc][i].second;

			if (sumDis + w < val[nextLoc]) {
				val[nextLoc] = sumDis + w;
				pq.push(make_pair(nextLoc, sumDis + w));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (val[i] == INT_MAX) {
			cout << "INF\n";
		}
		else
			cout << val[i] << '\n';
	}
}