#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;

int Combination(int n) {
	if (n == 1)
		return 1;
	else
		return n * (n - 1) / 2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long ans = 0;

	cin >> N;

	int buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		while (!s.empty() && s.top().first < buf) {
			ans += s.top().second;
			s.pop();
		}
		if (!s.empty() && s.top().first == buf) {
			ans += s.top().second++;
			if (s.size() >= 2) {
				ans++;
			}
		}
		else {
			if (s.size() >= 1) {
				ans++;
			}
			s.push({ buf, 1 });
		}
	}
	cout << ans;
}