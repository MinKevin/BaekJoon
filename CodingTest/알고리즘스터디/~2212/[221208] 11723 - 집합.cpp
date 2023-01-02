/*
Date : 22.12.08
Time : 06:32~
Comment : BitMasking!
*/

#include <iostream>

using namespace std;

int N;

int order;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string inp;
	while (N--) {
		cin >> inp;

		int x;
		if (inp == "add") {
			cin >> x;
			order |= 1 << x;
		}
		else if (inp == "remove") {
			cin >> x;
			order &= ~(1 << x);
		}
		else if (inp == "check") {
			cin >> x;
			if (order & 1 << x)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (inp == "toggle") {
			cin >> x;
			order ^= 1 << x;
		}
		else if (inp == "all") {
			order = ~0;
		}
		else if (inp == "empty") {
			order = 0;
		}
	}
}