#include <iostream>
#include <limits.h>
using namespace std;

int n, m;
int arr[1000000];

int solution(int max) {
	int st = 1;
	int en = max;
	int ans;

	while (st <= en) {
		int mid = (st + en) / 2;

		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= n) {
			ans = mid;
			st = mid + 1;
		}
		else {
			en = mid - 1;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int max = 0;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];

		if (arr[i] > max)
			max = arr[i];
	}

	cout << solution(max);
}