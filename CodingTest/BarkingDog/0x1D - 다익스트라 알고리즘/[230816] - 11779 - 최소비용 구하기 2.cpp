#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string>

using namespace std;

int n, m, st, en;
vector<int> value;
vector<int> nodeFrom;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<vector<pair<int, int>>> node;

void input() {
	cin >> n >> m;
	value.resize(n + 1, INT_MAX);
	nodeFrom.resize(n + 1);
	node.resize(n + 1, vector<pair<int, int>>());

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ cost, to });
	}

	cin >> st >> en;
}

void solution() {
	value[st] = 0;
	nodeFrom[st] = -1;
	pq.push({ 0, st });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost >= value[en])
			continue;

		for (int i = 0; i < node[cur].size(); i++) {
			int nCost = node[cur][i].first;
			int nxtNode = node[cur][i].second;

			if (value[nxtNode] > cost + nCost) {
				value[nxtNode] = cost + nCost;
				nodeFrom[nxtNode] = cur;
				pq.push(make_pair(value[nxtNode], nxtNode));
			}
		}
	}

	int tmp = en;
	vector<int> ans;
	while (tmp != -1) {
		ans.push_back(tmp);
		tmp = nodeFrom[tmp];
	}

	cout << value[en] << '\n';
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	solution();
}