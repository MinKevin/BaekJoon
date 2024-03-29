﻿#include <iostream>
#include <queue>
#include <vector> 

using namespace std;

int N, K;
int board[100001];
int vis[100001];


int Bfs(int K) {
	if (N == K)
		return 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, N });
	vis[N] = 1;

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (cur.second == K)
			return cur.first;

		if (cur.second * 2 <= 100000 && !vis[cur.second * 2]) {
			vis[cur.second * 2] = 1;
			pq.push({ cur.first, cur.second * 2 });
		}

		if (cur.second + 1 <= 100000 && !vis[cur.second + 1]) {
			vis[cur.second + 1] = 1;
			pq.push({ cur.first + 1, cur.second + 1 });
		}
		if (cur.second - 1 >= 0 && !vis[cur.second - 1]) {
			vis[cur.second - 1] = 1;
			pq.push({ cur.first + 1, cur.second - 1 });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;

	cout << Bfs(K);
}