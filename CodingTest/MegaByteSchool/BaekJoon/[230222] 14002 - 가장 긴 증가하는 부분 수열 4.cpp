#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, input;
	vector<int> answer;
	vector<pair<int, int>> v;
	vector<vector<int>> lis;

	cin >> N;
	lis.resize(N, vector<int>());

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back({ input, 1 });
	}

	for (int i = 0; i < v.size(); i++) {
		lis[i].push_back(v[i].first);
		for (int j = i - 1; j >= 0; j--) {
			if (v[i].first > v[j].first) {
				if (v[j].second + 1 > v[i].second) {
					lis[i].clear();
					lis[i] = lis[j];
					lis[i].push_back(v[i].first);
					v[i].second = v[j].second + 1;
				}
			}
		}
		if (answer.size() < lis[i].size())
			answer = lis[i];
	}
	cout << answer.size() << '\n';
	for (auto v : answer)
		cout << v << ' ';
}