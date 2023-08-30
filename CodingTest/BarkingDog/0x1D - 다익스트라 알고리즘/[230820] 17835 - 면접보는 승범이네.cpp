#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define ll long long

using namespace std;

int N, M, K;
vector<vector<pair<ll, int>>> node;
vector<int> meetingSpot;
vector<ll> value;
void input() {
	cin >> N >> M >> K;

	node.resize(N + 1, vector<pair<ll, int>>());
	value.resize(N + 1, LLONG_MAX);
	for (int i = 0; i < M; i++) {
		int st, en, cost;
		cin >> st >> en >> cost;
		node[en].push_back({ cost, st });
	}

	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;
		meetingSpot.push_back(k);
	}
}

void solution() {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

	for (int i = 0; i < meetingSpot.size(); i++) {
		value[meetingSpot[i]] = 0;
		pq.push({ 0, meetingSpot[i] });
	}

	while (!pq.empty()) {
		ll cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		if (value[vertex] < cost)
			continue;

		for (int i = 0; i < node[vertex].size(); i++) {
			ll nCost = node[vertex][i].first;
			int nVertex = node[vertex][i].second;

			if (value[nVertex] > cost + nCost) {
				value[nVertex] = cost + nCost;
				pq.push({ value[nVertex], nVertex });
			}
		}
	}
	ll dis = 0, num = 0;
	for (int i = 1; i <= N; i++) {
		if (value[i] > dis) {
			dis = value[i];
			num = i;
		}
	}
	cout << LLONG_MAX << '\n';
	cout << num << '\n' << dis;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}