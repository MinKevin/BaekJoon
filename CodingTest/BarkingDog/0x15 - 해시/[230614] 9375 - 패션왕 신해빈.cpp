#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int T, n;
int memoization[30][30];
unordered_map<string, vector<string>> mp;
vector<int> answer;

void input() {
	cin >> T;
}

int recur(unordered_map<string, vector<string>>::iterator it, int cnt, int target) {
	if (cnt == target) {
		return 1;
	}
	if (it == mp.end())
		return 0;

	int ans = 0;

	if (memoization[distance(mp.begin(), it)][target - cnt] == -1) {
		for (auto itBuf = it; itBuf != mp.end();) {
			ans += itBuf->second.size() * recur(++itBuf, cnt + 1, target);
		}
	}
	else
		return memoization[distance(mp.begin(), it)][target - cnt];

	memoization[distance(mp.begin(), it)][target - cnt] = ans;
	return ans;
}

void solution() {
	fill(&memoization[0][0], &memoization[29][30], -1);
	mp = unordered_map<string, vector<string>>();

	cin >> n;
	string name, sort;
	for (int i = 0; i < n; i++) {
		cin >> name >> sort;
		mp[sort].push_back(name);
	}

	int ans = 0;
	for (int i = 1; i <= mp.size(); i++) {
		ans += recur(mp.begin(), 0, i);
	}
	answer.push_back(ans);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < T; i++)
		solution();

	for (auto v : answer)
		cout << v << '\n';
}