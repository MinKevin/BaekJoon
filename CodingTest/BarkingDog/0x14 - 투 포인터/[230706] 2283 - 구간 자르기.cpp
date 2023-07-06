#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, K;
int loc[1000001];
int minLoc = INT_MAX, maxLoc;

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < y; j++)
			loc[j]++;

		if (x < minLoc)
			minLoc = x;
		if (y > maxLoc)
			maxLoc = y;
	}
}

pair<int, int> solution() {
	int sum = 0, en = minLoc;

	for (int st = 0; st < maxLoc; st++) {
		while (en < maxLoc && sum < K) {
			sum += loc[en++];
		}
		if (sum == K)
			return make_pair(st, en);
		sum -= loc[st];
	}
	return make_pair(0, 0);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	pair<int, int> rst = solution();
	cout << rst.first << ' ' << rst.second;
}