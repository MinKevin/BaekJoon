#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int pos = 0;
	bool reachedAtMax = false;
	for (int i = 0; i < 2 * N - 1; i++) {
		for (int j = 0; j < 2 * N; j++) {
			if (j <= pos || j >= 2 * N - 1 - pos) {
				cout << '*';
			}
			else
				cout << ' ';
		}
		cout << '\n';
		if (reachedAtMax == false) {
			pos++;
			if (pos == N - 1)
				reachedAtMax = true;
		}
		else
			pos--;
	}
}