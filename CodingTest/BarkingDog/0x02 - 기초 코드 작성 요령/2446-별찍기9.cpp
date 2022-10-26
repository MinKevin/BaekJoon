#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int pos = 0;
	bool isReachedAtMax = false;
	for (int i = 1; i <= 2 * N - 1; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (j < pos)
				cout << ' ';
			else if (j > 2 * N - 2 - pos)
				continue;
			else
				cout << '*';
		}
		if (isReachedAtMax == false) {
			pos++;
			if (pos == N - 1) {
				isReachedAtMax = true;
			}
		}
		else
			pos--;

		cout << '\n';
	}
}