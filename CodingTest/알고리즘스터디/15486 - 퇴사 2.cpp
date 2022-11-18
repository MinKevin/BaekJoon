

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;
long maxIncome[1500002];
int answer;

void DP() {
	for (int i = 0; i <= N; i++) {
		int expectedDate = (i + 1) + v[i].first;
		if (maxIncome[i + 1] > answer) 
			answer = maxIncome[i + 1];
		

		if (expectedDate > N + 1) {
			continue;
		}

		if (answer + v[i].second > maxIncome[expectedDate])
			maxIncome[expectedDate] = answer + v[i].second;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int T, P;
	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		v.push_back(make_pair(T, P));
	}

	/*N = 1500000;

	for (int i = 0; i < N; i++) {
		v.push_back({ 1, 1000 });
	}*/

	DP();

	cout << answer;
}