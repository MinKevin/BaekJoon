#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, M, K, X;

vector<int> node[300001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int answer[300001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> X;
	int st, en;
	for (int i = 0; i < M; i++) {
		cin >> st >> en;
		node[st].push_back(en);
	}
	fill(&answer[0], &answer[N + 1], INF);

	answer[X] = 0;
	pq.push({ 0, X });
	while (!pq.empty()) {
		int loc = pq.top().second;
		int sumDis = pq.top().first;
		pq.pop();

		if (answer[loc] < sumDis)
			continue;

		for (int i = 0; i < node[loc].size(); i++) {
			int target = node[loc][i];

			if (sumDis + 1 < answer[target]) {
				answer[target] = sumDis + 1;
				pq.push({ sumDis + 1, target});
			}
		}
	}

	bool hasK = false;
	for (int i = 1; i <= N; i++) {
		if (answer[i] == K) {
			hasK = true;
			cout << i << '\n';
		}
	}
	if (hasK == false)
		cout << -1 << '\n';

}