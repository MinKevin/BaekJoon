#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> v;

int func() {
	//int min = 0;
	//int max = v[N - 1] - 1;
	int min = 0;
	int max = v.back();
	int result;

	while (min <= max) {
		int cnt = 1;
		int mid = (min + max) / 2;
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
			min = mid + 1;
		}
		else {
			max = mid - 1;
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