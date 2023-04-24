#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> population(1, 0);
vector<vector<int>> road;
vector<vector<int>> v;
vector<bool> isUsed;
int ans;

void input() {
	cin >> N;
	road.resize(N + 1, vector<int>());
	isUsed.resize(N + 1, false);

	for (int i = 0; i < N; i++) {
		int inp;
		cin >> inp;
		population.push_back(inp);
	}
	int from, to;	
	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to;
		road[from].push_back(to);
		road[to].push_back(from);
	}
}

void recur(int loc) {
	isUsed[loc] = true;

	v[loc][0] = 0;
	v[loc][1] = population[loc];

	for (int i = 0; i < road[loc].size(); i++) {
		int nxt = road[loc][i];
		if (isUsed[nxt] == true)
			continue;
		recur(nxt);
		v[loc][0] += max(v[nxt][0], v[nxt][1]);
		v[loc][1] += v[nxt][0];
	}
}

int solution() {
	v.resize(N + 1, vector<int>(2, -1));

	recur(1);

	return max(v[1][0], v[1][1]);
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}