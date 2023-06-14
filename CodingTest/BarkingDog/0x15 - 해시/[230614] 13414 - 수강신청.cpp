#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int K, L;
unordered_map<string, int> mp;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}

void input() {
	cin >> K >> L;

	string inp;
	for (int i = 1; i <= L; i++) {
		cin >> inp;
		//mp.insert(make_pair(inp, i));
		mp[inp] = i;
	}
}

void solution() {
	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < (K < v.size() ? K : v.size()); i++) {
		cout << v[i].first << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}