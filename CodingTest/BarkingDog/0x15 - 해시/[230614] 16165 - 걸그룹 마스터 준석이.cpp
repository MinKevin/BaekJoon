#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
map<string, string> nameAndGroup;
map<string, vector<string>> groupAndName;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string groupName, memberName;
		int cnt;
		cin >> groupName >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> memberName;
			groupAndName[groupName].push_back(memberName);
			nameAndGroup[memberName] = groupName;
		}
	}
}

void solution() {
	vector<string> ans;

	string question;
	int type;
	for (int i = 0; i < M; i++) {
		cin >> question >> type;
		if (type == 0) {
			sort(groupAndName[question].begin(), groupAndName[question].end(), less<>());
			for (string str : groupAndName[question]) {
				ans.push_back(str);
			}
		}
		else {
			ans.push_back(nameAndGroup[question]);
		}
	}

	for (string str : ans)
		cout << str << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}