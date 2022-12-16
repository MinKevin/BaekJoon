/*
Date : 22.12.16
Time : 10:17~
Comment:

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> line;
int N;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

void Solution() {
	long long answer = 0;
	int st = line[0].first;
	int en = line[0].second;
	
	for (int i = 1; i < line.size(); i++) {
		if (line[i].first > en) {
			answer += en - st;
			st = line[i].first;
			en = line[i].second;
			continue;
		}
		else if (line[i].second > en)
			en = line[i].second;
	}
	answer += en - st;
	cout << answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int st, en;
	while (N--) {
		cin >> st >> en;
		line.push_back({ st, en });
	}
	sort(line.begin(), line.end(), cmp);

	for (int i = 0; i < line.size(); i++) {
		cout << line[i].first << ' ' << line[i].second << '\n';
	}

	Solution();
}

