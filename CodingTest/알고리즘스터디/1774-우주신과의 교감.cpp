#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int N, M;

vector<int> nxt;
vector<pair<int, int>> coordinate;
vector < pair<double, pair<int, int>>> edge;

bool cmp(const pair<double, pair<int, int>> &a, const pair<double, pair<int, int>> b) {
	return a.first < b.first;
}

int find(int x) {
	if (nxt[x] == -1)
		return x;
	return nxt[x] = find(nxt[x]);
}

bool isDifGroup(int u, int v) {
	//cout << "ex u v : " << u << ' ' << v << '\n';
	u = find(u);
	v = find(v);
	//cout << "nxt u v : " << u << ' ' << v << '\n';

	if (u == v)
		return false;
	nxt[v] = u;
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	nxt.resize(N + 1, -1);

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coordinate.push_back(make_pair(x, y));
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		isDifGroup(a - 1, b - 1);
	}

	double r;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			r = sqrt(pow(coordinate[i].first - coordinate[j].first, 2) 
				+ pow(coordinate[i].second - coordinate[j].second, 2));
			edge.push_back({ r, {i, j} });
		}
	}

	sort(edge.begin(), edge.end(), cmp);
	

	double answer = 0;
	for (int i = 0; i < edge.size(); i++) {
		double cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (isDifGroup(a, b)) {
			//cout << a + 1<< ' ' << b + 1<< '\n';
			answer += cost;

		}
	}
	cout << fixed;
	cout.precision(2);
	cout << answer;
}