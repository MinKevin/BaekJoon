#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<ll> v;

ll solution() {
	ll ans = 0;
	sort(v.begin(), v.end(), less<>());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			if (i + 1 == v.size() || v[i + 1] > 0) {
				ans += v[i];
			}
			else if (v[i + 1] <= 0) {
				ans += v[i] * v[i + 1];
				i++;
			}
		}
		else if (v[i] == 0 || v[i] == 1) {
			ans += v[i];
		}
		else if (v[i] > 1) {
			if ((v.size() - i) % 2 == 0) {
				ans += v[i] * v[i + 1];
				i++;
			}
			else
				ans += v[i];
		}
		//cout << ans << '\n';
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		v.push_back(inp);
	}

	cout << solution();
}