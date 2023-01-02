/*

*/
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, H;
int top[500001];
int bottom[500001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> H;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (i % 2 == 0) {
			bottom[input]++;
		}
		else if (i % 2 == 1) {
			top[H - input + 1]++;
		}
	}

	for (int i = 1; i <= H; i++) {
		top[i] += top[i - 1];
		bottom[H - i] += bottom[H - i + 1];
	}

	long long answer = INT_MAX;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		if (top[i] + bottom[i] < answer) {
			cnt = 1;
			answer = top[i] + bottom[i];
		}
		else if (top[i] + bottom[i] == answer)
			cnt++;
	}
	cout << answer << ' ' << cnt;
}