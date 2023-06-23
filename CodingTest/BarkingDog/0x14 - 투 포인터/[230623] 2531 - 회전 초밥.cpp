#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, d, k, c;
vector<int> belt;
int kindsCnt[3001];
void input() {
	cin >> N >> d >> k >> c;

	belt.resize(N + k);
	for (int i = 0; i < N; i++) {
		cin >> belt[i];
		if (i < k)
			belt[N + i] = belt[i];
	}
}

int solution() {
	int cnt = 0, ans = 0;
	for (int i = 0; i < N + k; i++) {
		if (i >= k) {
			int exKind = belt[i - k];
			if (exKind != c && --kindsCnt[exKind] == 0)
				cnt--;
		}

		int kind = belt[i];
		if (kind != c && kindsCnt[kind]++ == 0)
			cnt++;
		ans = max(ans, cnt + 1);
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}