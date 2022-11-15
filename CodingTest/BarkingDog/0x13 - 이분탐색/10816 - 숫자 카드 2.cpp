#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int a[500005];

int lower_idx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] >= target) en = mid;
		else st = mid + 1;

	}
}

int upper_idx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] > target)
			en = mid;
		else
			st = mid + 1;
	}
	return st;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	cin >> M;
	while (M--) {
		int inp;
		cin >> inp;
		cout << upper_idx(inp, N) - lower_idx(inp, N) << '\n';
	}
}