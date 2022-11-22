﻿#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		cout << binary_search(a, a + n, t) << '\n';
	}
}