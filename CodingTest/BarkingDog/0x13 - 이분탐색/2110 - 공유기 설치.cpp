#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> v;

int func() {
	int st = 0;
	int end = v[N - 1] - 1;

	int result;

	while (st <= end) {
		int cnt = 1;
		int mid = (st + end) / 2;
		int startLoc = v[0];

		for (int i = 1; i < N; i++) {
			int endLoc = v[i];

			if (endLoc - startLoc >= mid) {
				cnt++;
				startLoc = endLoc;
			}
		}
		if (cnt >= C) {
			result = mid;
			st = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		v.push_back(inp);
	}
	sort(v.begin(), v.end(), less<>());
		
	cout << func();
}