#include <iostream>

using namespace std;

const int MX = 1000001;
pair<int, int> dat[MX];
int ans[MX];
int pos = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int buf;
	for (int i = 1; i <= N; i++) {
		cin >> buf;
		while (pos != 0 && dat[pos - 1].second < buf) {
			ans[dat[pos - 1].first] = buf;
			pos--;
		}
		dat[pos++] = make_pair(i, buf);

	}
	for (int i = 1; i <= N; i++) {
		if (ans[i] != 0)
			cout << ans[i] << ' ';
		else
			cout << "-1 ";

	}
}