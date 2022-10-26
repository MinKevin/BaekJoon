#include <iostream>

using namespace std;

const int MX = 1000001;
int dat[MX];
int head, tail;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dat[tail++] = i;
	}

	while (tail - head != 1) {
		head++;
		dat[tail++] = dat[head++];
	}
	cout << dat[head];
}