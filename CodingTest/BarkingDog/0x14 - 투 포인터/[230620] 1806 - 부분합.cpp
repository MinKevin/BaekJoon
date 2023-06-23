#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, S, ans = INT_MAX;
vector<int> v;

void input() {
	cin >> N >> S;
	v.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

int solution() {
	int en = 0;
	int sum = v[0];

	for (int st = 0; st < N; st++) {
		while (en < N && sum < S) {
			sum += v[++en];
		}

		if (en == N)
			break;

		if (ans >= en - st + 1) {
			ans = en - st + 1;
		}
		sum -= v[st];
	}
	if (ans == INT_MAX)
		return 0;
	else
		return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}