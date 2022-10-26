#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	int result;
	int answer[10] = {0, };

	cin >> A >> B >> C;

	result = A * B * C;
	while (result != 0) {
		answer[result % 10]++;
		result /= 10;
	}

	for (auto val : answer) {
		cout << val << '\n';
	}
}