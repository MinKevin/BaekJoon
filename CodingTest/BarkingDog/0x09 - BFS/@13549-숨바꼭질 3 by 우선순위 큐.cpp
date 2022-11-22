//우선순위 큐의 시간복잡도 : O(log2N)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int vis[100001];

int BFS() {
	if (N == K) {
		return 0;
	}
	
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, N });
	vis[N] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.top();
		q.pop();

		if (cur.second == K)
			return cur.first;

		if (cur.second * 2 <= 100000 && !vis[cur.second * 2]) {
			vis[cur.second * 2] = 1;
			q.push({ cur.first, cur.second * 2 });
		}

		if (cur.second + 1 <= 100000 && !vis[cur.second + 1]) {
			vis[cur.second + 1] = 1;
			q.push({ cur.first + 1, cur.second + 1 });
		}

		if (cur.second - 1 >= 0 && !vis[cur.second - 1]) {
			vis[cur.second - 1] = 1;
			q.push({ cur.first + 1, cur.second - 1 });
		}
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);; 

	cin >> N >> K;
	
	cout << BFS();
}