#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, L, val;
vector<int> v;

bool start(int dist) {
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int d = v[i + 1] - v[i];
		int val;
		if (d / dist > 0) {
			if (d % dist == 0)	val = (d / dist) - 1;
			else val = (d / dist);
			cnt += val;
		}
	}
	if (cnt <= M) return true;
	return false;
}

int main() {
	cin >> N >> M >> L;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}
	v.push_back(L);
	sort(v.begin(), v.end());
	int low = 1, high = L, mid, result;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (start(mid)) {
			high = mid - 1;
			result = mid;
		}
		else	low = mid + 1;
	}
	cout << result;
}