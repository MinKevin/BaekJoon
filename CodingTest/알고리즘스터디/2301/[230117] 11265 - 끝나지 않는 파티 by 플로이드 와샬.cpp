#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M;
vector<vector<int>> floyd;
vector<string> answer;

void FloydWarshall() {
	for (int by = 0; by < N; by++) {
		for (int from = 0; from < N; from++) {
			for (int to = 0; to < N; to++) {
				if (floyd[from][by] + floyd[by][to] < floyd[from][to])
					floyd[from][to] = floyd[from][by] + floyd[by][to];
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	floyd.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> floyd[i][j];
		}
	}

	FloydWarshall();

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;

		if (floyd[A - 1][B - 1] <= C)
			answer.push_back("Enjoy other party\n");
		else
			answer.push_back("Stay here\n");
	}

	for (auto v : answer)
		cout << v;
}