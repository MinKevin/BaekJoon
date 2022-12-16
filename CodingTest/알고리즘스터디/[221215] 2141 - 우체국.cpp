/*
Date : 22.12.15
Time : 08:37~
Comment :

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
vector<pair<long long, long long>> v;
long long sum;

int func() {
	long long cur = 0;
	for (int i = 0; i < N; i++) {
		cur += v[i].second;
		if (cur >= (sum + 1) / 2) {
			return v[i].first;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	long long X, A;
	for (int i = 0; i < N; i++) {
		cin >> X >> A;
		v.push_back({ X, A });
		sum += A;
	}
	sort(v.begin(), v.end());

	cout << func();
}