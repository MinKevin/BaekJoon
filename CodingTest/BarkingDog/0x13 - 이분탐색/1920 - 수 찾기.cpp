﻿#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int n;

int binarysearch(int target) {
	int st = 0;
	int en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (a[mid] < target)
			st = mid + 1;
		else if (a[mid] > target)
			en = mid - 1;
		else
			return 1;
	}
	return 0; // st > en일 경우 while문을 탈출
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, less<>());
	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		cout << binarysearch(t) << '\n';
	}
		
}