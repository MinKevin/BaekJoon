#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int T, n;
unordered_map<string, vector<string>> mp;
string answer;

void input() {
	cin >> T;
}

void solution() {
	mp = unordered_map<string, vector<string>>();
	cin >> n;
	if (n == 0) {
		answer += "0\n";
		return;
	}
	string name, sort;
	for (int i = 0; i < n; i++) {
		cin >> name >> sort;
		mp[sort].push_back(name);
	}

	int ans = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans *= it->second.size() + 1;
	}
	answer += to_string(ans - 1) + '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < T; i++)
		solution();

	cout << answer;
}