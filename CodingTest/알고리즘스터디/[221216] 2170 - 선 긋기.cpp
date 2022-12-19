/*
Date : 22.12.16
Time : 10:17 ~ 10:58 (41m)
Comment:
	sort됐을 때, 어떤 식으로 수가 정렬되는지 다시한번 생각해보자.
	
	https://www.acmicpc.net/source/52668684
	이 코드랑 방식은 비슷한데 차이가 왜 날까?
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

	Solution();
}