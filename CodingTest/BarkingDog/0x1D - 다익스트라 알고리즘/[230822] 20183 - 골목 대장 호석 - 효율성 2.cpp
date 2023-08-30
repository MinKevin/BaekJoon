#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
#include <algorithm>

# define ll long long

using namespace std;

int N, M, A, B;
ll C;
vector<vector<pair<int, int>>> node;
//maxShame, maxtotalFee
vector<pair<int, ll>> maxShames;
//maxShame, totalFee, From
priority_queue<tuple<int, ll, int>, vector<tuple<int, ll, int>>, greater<>> pq;

void input() {
	cin >> N >> M >> A >> B >> C;
	node.resize(N + 1, vector<pair<int, int>>());
	maxShames.resize(N + 1, { INT_MAX, C + 1 });
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ cost, to });
		node[to].push_back({ cost, from });
	}
}

ll solution() {
	maxShames[A] = { 0, 0 };
	pq.push({ 0, 0, A });

	while (!pq.empty()) {
		int maxShame = get<0>(pq.top());
		int totalFee = get<1>(pq.top());
		int vertex = get<2>(pq.top());
		pq.pop();

		if (maxShame > maxShames[vertex].first && totalFee > maxShames[vertex].second)
			continue;

		for (int i = 0; i < node[vertex].size(); i++) {
			int nxtMaxShame = node[vertex][i].first;
			int nxtVertex = node[vertex][i].second;

			if (maxShames[nxtVertex].first > max(maxShame, nxtMaxShame)
				&& totalFee + nxtMaxShame <= C) {
				maxShames[nxtVertex].first = max(maxShame, nxtMaxShame);
				maxShames[nxtVertex].second = totalFee + nxtMaxShame;
				pq.push({ maxShames[nxtVertex].first
					, maxShames[nxtVertex].second
					, nxtVertex});
			}
			else if (maxShames[nxtVertex].first == max(maxShame, nxtMaxShame)
				&& maxShames[nxtVertex].second > totalFee + nxtMaxShame) {
				maxShames[nxtVertex].second = totalFee + nxtMaxShame;
				pq.push({ maxShames[nxtVertex].first
					, maxShames[nxtVertex].second
					, nxtVertex });
			}
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	cout << maxShames[i].first << ' ' << maxShames[i].second << '\n';
	//}

	if (maxShames[B].second == C + 1)
		return -1;
	else
		return maxShames[B].first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

}

/*
반례
5 5 1 5 10
1 2 2
2 3 2
3 4 2
1 4 4
4 5 6

정답 6
*/