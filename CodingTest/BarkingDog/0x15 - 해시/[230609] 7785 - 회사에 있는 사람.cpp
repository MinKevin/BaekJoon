#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
map<string, vector<string>, greater<string>> mp;

void solution() {
	string ans = "";
	for (map<string, vector<string>, greater<string>>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second.back() == "enter") {
			cout << it->first << '\n';
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	string name, state;
	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		mp[name].push_back(state);
	}

	solution();
}