//https://kbw1101.tistory.com/29

#include <iostream>

using namespace std;

long N, K;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	int lo = 1, result = 0;
	long hi = N * N, mid;
	while (1) {
		int cnt = 0;

		if (lo > hi) break;

		mid = (lo + hi) / 2;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
			if (cnt >= K)
				break;
		}

		if (cnt >= K) {
			result = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}

	cout << result;
}