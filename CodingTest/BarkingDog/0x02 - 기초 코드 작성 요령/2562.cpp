#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int max = 0;
	int max_index;
	int index = 1;
	int input;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		if (input > max) {
			max = input;
			max_index = index;
		}
		index++;
	}
	cout << max << '\n' << max_index;
}