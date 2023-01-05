/*
Date : 230104
Time : 21:07 ~ 
Comment : 
*/

#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector<pair<int, int>> v;
int maxIncome[1500002];

void func() {
	for (int i = 0; i < N; i++) {
		if (maxIncome[i + 1] > answer)
			answer = maxIncome[i + 1];

		int expectedDate = (i + 1) + v[i].first;
		if (expectedDate > N + 1)
			continue;

		cout << answer + v[i].second << ' ';
		if (answer + v[i].second > maxIncome[expectedDate])
			maxIncome[expectedDate] = answer + v[i].second;
	}
	if (maxIncome[N + 1] > answer)
		answer = maxIncome[N + 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	func();
	cout << answer;
}