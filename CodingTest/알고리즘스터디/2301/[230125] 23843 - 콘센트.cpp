#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<>> pq;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < min(N, M); i++) {
		pq.push(v[i]);
	}

	for (int i = M; i < N; i++) {
		int top = pq.top();
		pq.pop();
		pq.push(top + v[i]);
	}

	while (pq.size() != 1) {
		pq.pop();
	}

	cout << pq.top();
}