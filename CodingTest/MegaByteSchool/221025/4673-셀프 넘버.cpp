#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool chk[10001] = { false, };

	for (int b = 0; b < 10; b++) {
		for (int c = 0; c < 10; c++) {
			for (int d = 0; d < 10; d++) {
				for (int e = 0; e < 10; e++) {
					int result = 1001 * b + 101 * c + 11 * d + 2 * e;
					if (result <= 10000) {
						chk[result] = true;
					}
					else 
						break;
				}
			}
		}
	}


	for (int i = 1; i < 10001; i++) {
		if (chk[i] == false) {
			cout << i << '\n';
		}
	}
}