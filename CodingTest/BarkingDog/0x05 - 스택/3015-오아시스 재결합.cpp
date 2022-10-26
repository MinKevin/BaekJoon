#include <iostream>

using namespace std;

const int MX = 500001;
pair<int, int> dat[MX];
int pos = 0;

int Combination(int n) {
	if (n == 1)
		return 1;
	else
		return n * (n - 1) / 2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long ans = 0;
	
	cin >> N;

	int buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		while (pos != 0 && dat[pos - 1].first < buf) {
				ans += dat[pos - 1].second;
				pos--;
		}

		if (dat[pos - 1].first == buf) {
			ans += dat[pos - 1].second;
			if (pos >= 2) {
				ans += 1;
			}
			dat[pos - 1].second++;
			continue;
		}

		if (pos > 0)
			ans += 1;
		dat[pos++] = { buf, 1 };

		//cout << "ans : " << ans << '\n';
	}

	cout << ans << '\n';

}