#include <iostream>
#include <unordered_map>
#include <string.h>

#define ll unsigned long long

using namespace std;


ll N, P, Q;
unordered_map<ll, ll> mp;

void input() {
	cin >> N >> P >> Q;
}

ll recur(ll n) {
	if (mp.find(n) != mp.end())
		return mp[n];

	mp[n] = recur(n / P) + recur(n / Q);
	return mp[n];
}

ll solution() {
	//memset(&v, -1, N * sizeof(ll));
	//v.resize(N + 1, -1);
	//v = vector<ll>(N + 1, -1);
	mp[0] = 1;
	return recur(N);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}