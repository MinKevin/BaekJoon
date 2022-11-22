#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int buf;
	int min = 100;
	int answer = 0;

	for (int i = 0; i < 7; i++) {
		cin >> buf;
		if (buf % 2 == 1) {
			answer += buf;
			if (buf < min)
				min = buf;
		}
	}
	if (answer == 0) {
		cout << -1;
	}
	else
		cout << answer << '\n' << min;
}