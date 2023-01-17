#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M;
vector<vector<int>> node;
vector<vector<int>> val;
vector<string> answer;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void daijkstra() {
	for (int from = 0; from < N; from++) {
		pq.push({ 0, from });
		val[from][from] = 0;

		while (!pq.empty()) {
			int disSum = pq.top().first;
			int loc = pq.top().second;
			pq.pop();

			for (int to = 0; to < N; to++) {
				int x = node[loc][to];
				if (disSum + x < val[from][to]) {
					val[from][to] = disSum + x;
					pq.push({ val[from][to], to });
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	node.assign(N, vector<int>(N, 0));
	val.assign(N, vector<int>(N, INF));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> node[i][j];
		}
	}

	daijkstra();

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;

		if (val[A - 1][B - 1] <= C)
			answer.push_back("Enjoy other party\n");
		else
			answer.push_back("Stay here\n");
	}

	for (auto v : answer)
		cout << v;
}