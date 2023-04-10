#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int vis[100001];
int N, K;
int dx[2] = { 1, -1 };
queue<pair<int, int>> q;

void func(int t, int loc) {
	if (loc * 2 <= 100000 && vis[loc * 2] == -1) {
		vis[loc * 2] = t;
		if (loc * 2 == K) {
			cout << t << "\n";
			exit(0);
		}
		func(t, loc * 2);
	}

	for (int i = 0; i < 2; i++) {
		int nx = loc + dx[i];

		if (nx < 0 || nx > 100000)
			continue;


		if (vis[nx] == -1) {
			q.push({ t + 1, nx });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	if (N == K) {
		cout << 0 << '\n';
		return 0;
	}

	fill(&vis[0], &vis[100001], -1);
	
	q.push({ 0, N });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (vis[cur.second] == -1) {
			if (cur.second == K) {
				cout << cur.first << "\n";
				return 0;
			}
			//cout << cur.first << ' ' << cur.second << '\n';
			vis[cur.second] = cur.first;
			func(cur.first, cur.second);

		}
	}
}