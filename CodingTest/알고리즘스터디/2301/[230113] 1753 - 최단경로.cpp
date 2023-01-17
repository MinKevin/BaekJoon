#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define INF 987654321

using namespace std;

vector<pair<int, int> > node[20005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
int value[20005];

int main() {
	int n, e, k;
	int u, v, w;

	cin >> n >> e >> k;

	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= n; i++)
		value[i] = INF;

	value[k] = 0;

	pq.push(make_pair(0, k));

	while (!pq.empty()) {
		int x = pq.top().first;
		int U = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[U].size(); i++) {
			int V = node[U][i].first;
			int W = node[U][i].second;

			if (x + W < value[V]) {
				value[V] = x + W;
				pq.push(make_pair(x + W, V));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (value[i] == INF)
			cout << "INF\n";
		else
			cout << value[i] << '\n';
	return 0;
}