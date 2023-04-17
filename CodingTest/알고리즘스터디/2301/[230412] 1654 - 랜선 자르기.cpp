#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	vector<ll> v;


	cin >> K >> N;

	ll inp;
	ll left = 1;
	ll right = 0;

	for (int i = 0; i < K; i++) {
		cin >> inp;
		v.push_back(inp);
		right = max(right, inp);
	}

	
	ll ans = 0;
	while (left <= right) {
		//cout << left << ' ' << right << '\n';

		ll mid = (right + left) / 2;
		ll cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += v[i] / mid;
		}
		
		if (cnt >= N) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;
}