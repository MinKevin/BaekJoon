#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}

	hanoi(n - 1, from, to, by);
	cout << from << ' ' << to << '\n';
	hanoi(n - 1, by, from, to);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int K, A, B;

	cin >> N;

	K = pow(2, N) - 1;
	cout << K << '\n';

	hanoi(N, 1, 2, 3);

	return 0;
}