#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

int N, K, C;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jewelrys;
priority_queue<int, vector<int>, greater<int>> bags;


void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int M, V;
		cin >> M >> V;
		jewelrys.push(make_pair(M, V));
	}
	for (int i = 0; i < K; i++) {
		int ci;
		cin >> ci;
		bags.push(ci);
	}
}

ll solution() {
	ll ans = 0;
	priority_queue<int, vector<int>, less<int>> pq;
	while (!bags.empty()) {
		int capacity = bags.top();
		bags.pop();
		while (!jewelrys.empty() && jewelrys.top().first <= capacity) {
			pq.push(jewelrys.top().second);
			jewelrys.pop();
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
			
	}

	return ans;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}