#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define ll long long
using namespace std;

int N, M;
ll ans = LLONG_MAX;
vector<ll> v;

void input() {
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];
}

ll solution() {
	int st = 0, en = 1;
	sort(v.begin(), v.end(), less<>());
	while (true) {
		ll difference = v[en] - v[st];

		if (difference < M)
			en++;
		else {
			if (difference < ans)
				ans = difference;
			
			if (en - st == 1)
				en++;
			else
				st++;
		}

		if (en == N)
			return ans;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}

/*
1 3 4 5 6

*/