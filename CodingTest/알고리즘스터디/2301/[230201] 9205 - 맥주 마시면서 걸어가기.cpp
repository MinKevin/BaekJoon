#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int t, n;
vector<pair<int, int>> loc;
vector<int> kindsCnt;
vector<vector<int>> dis;
vector<string> answer;
string func() {
	dis = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
	kindsCnt = vector<int>(n + 2, 0);
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			dis[i][j] = abs(loc[i].first - loc[j].first)
				+ abs(loc[i].second - loc[j].second);
			//cout << dis[i][j] << ' ';
		}
		//cout << '\n';
	}

	if (dis[0][n + 1] <= 1000)
		return "happy";

	queue<int> q;
	q.push(0);
	kindsCnt[0] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//cout << cur << ' ';

		if (dis[cur][n + 1] <= 1000) {
			return "happy";
		}

		for (int i = 0; i < n + 1; i++) {
			if (kindsCnt[i] == 0 && dis[cur][i] <= 1000) {
				kindsCnt[i] = 1;
				q.push(i);
			}
		}
	}
	return "sad";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		loc = vector<pair<int, int>>();

		int x, y;

		cin >> n;

		for (int i = 0; i < n + 2; i++) {
			cin >> x >> y;
			loc.push_back({ x, y });
		}
		answer.push_back(func());
	}

	for (auto ans : answer)
		cout << ans << '\n';
}