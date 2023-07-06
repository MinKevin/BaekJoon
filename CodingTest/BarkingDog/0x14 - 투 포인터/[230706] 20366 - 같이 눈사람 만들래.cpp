#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int N;
vector<int> v;
int ans = INT_MAX;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int inp;
		cin >> inp;
		v.push_back(inp);
	}
}

int solution() {
	sort(v.begin(), v.end(), less<>());
	for (int a = 0; a < N - 3; a++) {
		for (int b = a + 3; b < N; b++) {	
			int fstSnowMan = v[a] + v[b];
			int l = a + 1;
			int r = b - 1;

			while (l < r) {
				int scdSnowMan = v[l] + v[r];
				ans = min(ans, abs(fstSnowMan - scdSnowMan));
				if (fstSnowMan < scdSnowMan)
					r--;
				else
					l++;
			}

		}
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}