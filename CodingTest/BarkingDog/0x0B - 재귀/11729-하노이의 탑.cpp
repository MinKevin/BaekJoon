#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int N, int A, int B, int C) {
	if (N == 1) {
		cout << A << ' ' << C << '\n';
		return;
	}
	hanoi(N - 1, A, C, B);
	cout << A << ' ' << C << '\n';
	hanoi(N - 1, B, A, C);
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
}