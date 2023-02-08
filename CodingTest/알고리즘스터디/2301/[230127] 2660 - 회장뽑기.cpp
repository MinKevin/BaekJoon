#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<vector<int>> floyd;
vector<int> answer;
int N;

void func() {
	for (int by = 1; by <= N; by++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if (floyd[from][by] == INT_MAX || floyd[by][to] == INT_MAX)
					continue;

				if (floyd[from][by] + floyd[by][to] < floyd[from][to]) {
					floyd[from][to] = floyd[from][by] + floyd[by][to];
				}
			}
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << floyd[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	int min = INT_MAX;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp = max(temp, floyd[i][j]);
		}
		if (temp < min) {
			min = temp;
			answer.clear();
			answer.push_back(i);
		}
		else if (temp == min) {
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end(), less<>());

	cout << min << ' ' << answer.size() << '\n';

	for (auto v : answer)
		cout << v << ' ';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> N;
	floyd.assign(N + 1, vector<int>(N + 1, INT_MAX));

	for (int i = 1; i <= N; i++) {
		floyd[i][i] = 0;
	}

	int st, en;
	while (true) {
		cin >> st >> en;
		if (st == -1 && en == -1)
			break;
		floyd[st][en] = 1;
		floyd[en][st] = 1;
	}

	func();
}