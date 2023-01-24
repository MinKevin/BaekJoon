#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

int V, E, ans;
int Parent[MAX];
vector<pair<int, pair<int, int>>> v;

int find(int x) {
	if (Parent[x] == x)
		return x;
	else
		return Parent[x] = find(Parent[x]);
}

void union_(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y)
		Parent[y] = x;
}

bool sameParent(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return true;
	else
		return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ cost, {from, to} });
	}
	sort(v.begin(), v.end(), less<>());

	for (int i = 1; i <= V; i++) {
		Parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		if (sameParent(v[i].second.first, v[i].second.second) == false) {
			union_(v[i].second.first, v[i].second.second);
			ans = ans + v[i].first;
		}
	}

	cout << ans;
}